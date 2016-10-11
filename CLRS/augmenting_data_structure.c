#include <stdio.h>
#define RED 0;
#define BLACK 1;
typedef struct rb_tree_node
{
	unsigned char color;
	int key;
	unsigned int size;
	struct rb_tree_node *parent;
	struct rb_tree_node *left;
	struct rb_tree_node *right;
}node_t;
typedef struct rb_tree
{
	node_t *root;
	node_t *nil;
}tree_t;

node_t *os_select(node_t *x, int i)
{
	int r = x->left->size + 1;
	if (i == r)
		return x;
	else if (i < r)
		return os_select(x->left, i);
	else
		return os_select(x->right, i - r);
}

node_t *os_select_nonrecursive(node_t *x, int i)
{
	int r = x->left->size + 1;
	while (i != r)
	{
		if (i < r)
		{
			x = x->left;
			r = x->left->size + 1;
		}			
		else
		{
			x = x->right;
			i = i - r;
			r = x->left->size + 1;
		}
	}
	return x;
}

int os_rank(tree_t *T, node_t *x)
{
	int r = x->left->size + 1;
	node_t *y = x;
	while (y != T->root)
	{
		if (y == y->parent->right)
			r += (y->parent->left->size + 1);
		y = y->parent;
	}
	return r;
}

int os_rank_recursive(node_t *t, int x)
{
	int r = t->left->size + 1;
	if (t->key == x)
		return r;
	else if (t->key > x)
		return os_rank_recursive(t->left, x);
	else
		return r + os_rank_recursive(t->right, x);
}


int main(void)
{
	return 0;
}