#include <stdio.h>
#include <stdlib.h>
#define KEY_MAX (unsigned)-1
#define KEY_MIN (int)1<<31
typedef int key_t;
typedef int degree_t;
typedef struct binomial_tree_node
{
	key_t key = 0;
	degree_t degree = 0;
	struct binomial_tree_node *parent = NULL;
	struct binomial_tree_node *child = NULL;
	struct binomial_tree_node *sibling = NULL;
}node_t;
typedef struct binomial_tree
{
	node_t *head = NULL;
}tree_t;

tree_t *make_binomial_heap(void)
{
	tree_t *new_tree = (tree_t *)malloc(sizeof(tree_t));
	new_tree->head = NULL;
	return new_tree;
}
node_t *make_binomial_node(key_t key = 0)
{
	node_t temp;
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->child = temp.child;
	new_node->degree = temp.degree;
	new_node->key = key;
	new_node->parent = temp.parent;
	new_node->sibling = temp.sibling;
	return new_node;
}
node_t *binomial_heap_minumun(tree_t *T)
{
	node_t *y = NULL;
	node_t *x = T->head;
	key_t min = KEY_MAX;
	while (x != NULL)
	{
		if (x->key < min)
		{
			min = x->key;
			y = x;
		}
		x = x->sibling;
	}
	return y;
}
void binomial_link(node_t *child_node, node_t *parent_node)
{
	child_node->parent = parent_node;
	child_node->sibling = parent_node->child;
	parent_node->child = child_node;
	parent_node->degree += 1;
}
tree_t *binomial_heap_merge(tree_t *Ta, tree_t *Tb)
{
	node_t *node_a = Ta->head, *node_b = Tb->head, *prev_node_a = NULL, *temp = NULL;
	if (node_a == NULL) // free Ta
		return Tb;
	if (node_b == NULL) // free Tb
		return Ta;
	if (node_a->degree > node_b->degree)
	{ //left insert
		temp = node_b;
		node_b = temp->sibling;
		temp->sibling = node_a;
		node_a = temp;
		Ta->head = node_a;
	}
	while (node_b != NULL)
	{
		if (node_a->sibling == NULL)
		{
			node_a->sibling = node_b;
			node_b = NULL;
		}

		else if (node_a->sibling->degree >= node_b->degree)
		{
			temp = node_b->sibling;
			node_b->sibling = node_a->sibling;
			node_a->sibling = node_b;
			node_b = temp;
		}
		else
		{
			node_a = node_a->sibling;
		}
	}
	//free Tb
	return Ta;
}

tree_t *binomial_heap_union(tree_t *Ha, tree_t *Hb)
{
	node_t *prev_h = NULL, *next_h = NULL, *h = NULL;
	tree_t *H = make_binomial_heap();
	H = binomial_heap_merge(Ha, Hb);
	if (H->head == NULL)
		return H;
	h = H->head;
	next_h = h->sibling;
	while (next_h != NULL)
	{
		if (h->degree != next_h->degree || (next_h->sibling != NULL && h->degree == next_h->sibling->degree))
		{
			prev_h = h;
			h = next_h;
		}
		else if (h->key <= next_h->key)
		{
			h->sibling = next_h->sibling;
			binomial_link(next_h, h);
		}
		else
		{
			if (prev_h == NULL)
				H->head = next_h;
			else
				prev_h->sibling = next_h;
			binomial_link(h, next_h);
			h = next_h;
		}
		next_h = h->sibling;
	}
	return H;
}
void binomial_heap_insert(tree_t *H, key_t key)
{
	tree_t *new_tree = make_binomial_heap();
	node_t *new_node = make_binomial_node(key);
	new_tree->head = new_node;
	H = binomial_heap_union(H, new_tree);
}
node_t *binomial_reverse(node_t *node)
{
	node_t *prev_node = NULL, *next_node = node;
	while (next_node != NULL)
	{
		node = next_node;
		next_node = next_node->sibling;
		node->sibling = prev_node;
		prev_node = node;
	}
	return prev_node;
}
node_t *binomial_heap_extract_min(tree_t *H)
{
	node_t *min_node = H->head, *min_prev = NULL, *temp = H->head, *temp_prev = NULL;
	tree_t *new_tree = make_binomial_heap();
	key_t min = KEY_MAX;
	while (temp != NULL)
	{
		if (temp->key < min)
		{
			min = temp->key;
			min_node = temp;
			min_prev = temp_prev;
		}
		temp_prev = temp;
	}
	if (min_prev == NULL)
		H->head = H->head->sibling; //head
	else
		min_prev->sibling = min_node->sibling;
	//reverse order
	node_t *children = min_node->child;
	children = binomial_reverse(children); //reverse
	new_tree->head = children;
	H = binomial_heap_union(H, new_tree);
	return min_node;
}

bool binomial_heap_decrease_key(tree_t *H, node_t *node, key_t new_key)
{
	if (new_key > node->key)
	{
		fprintf(stderr, "new key is greater than current key");
		return false;
	}
	node->key = new_key;
	node_t *y = node;
	node_t *z = node->parent;
	key_t temp = KEY_MAX;
	while (z != NULL && y->key < z->key)
	{
		temp = z->key;
		z->key = y->key;
		y->key = temp;
		y = z;
		z = y->parent;
	}
	return true;
}
void binomial_heap_delete(tree_t *H, node_t *node)
{
	binomial_heap_decrease_key(H, node, KEY_MIN);
	binomial_heap_extract_min(H);
}
int main(void)
{
	int a = 1;
	printf("%d\n", a<<31);
	printf("%u\n", a);
	printf("%x\n", a>>32);
	return 0;
}