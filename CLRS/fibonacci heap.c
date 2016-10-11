#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define KEY_MIN 1<<31
typedef int degree_t;
typedef int key_t;
typedef struct fibonacci_node_t
{
	degree_t degree = 0;
	key_t key = 0;
	bool mark = false;
	fibonacci_node_t *parent = NULL;
	fibonacci_node_t *child = NULL;
	fibonacci_node_t *left = NULL;
	fibonacci_node_t *right = NULL;
}node_t;
typedef struct fibonacci_heap_t
{
	node_t *min;
	int n = 0;
}heap_t;
typedef struct arr_t
{
	int length;
	node_t **start;
};
heap_t *make_fib_heap(void)
{
	heap_t *new_heap = (heap_t *)malloc(sizeof(heap_t));
	new_heap->min = NULL;
	new_heap->n = 0;
	return new_heap;
}
node_t *make_fib_node(key_t key = NULL)
{
	node_t temp;
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->right = new_node->left = new_node;
	new_node->parent = new_node->child = NULL;
	new_node->degree = temp.degree;
	new_node->key = key == NULL ? temp.key : key;
	new_node->mark = temp.mark;
	return new_node;
}
bool fib_list_concatenate(node_t *node, node_t *new_node)
{
	if (node == NULL || new_node == NULL)
		return false;
	if (new_node->left == new_node)
	{
		new_node->right = node->right;
		new_node->left = node;
		node->right->left = new_node;
		node->right = new_node;
	}
	else if (node->left == node)
	{
		node->right = new_node->right;
		node->left = new_node;
		new_node->right->left = node;
		new_node->right = node;
	}
	else
	{
		new_node->right->left = node->left;
		node->left->right = new_node->right;
		new_node->right = node;
		node->left = new_node;
	}
	return true;
}
bool fib_list_delete(node_t *list, node_t *node)
{
	if (list->right == list)
		list = NULL;
	else
	{
		node->left->right = node->right;
		node->right->left = node->left;
	}
	return true;
}

void fib_heap_insert(heap_t *H, key_t key)
{
	node_t *new_node = make_fib_node(key);
	fib_list_concatenate(H->min, new_node);
	if (H->min == NULL || key < H->min->key)
		H->min = new_node;
	H->n += 1;
}

heap_t *fib_heap_union(heap_t *H1, heap_t *H2)
{
	heap_t *new_H = make_fib_heap();
	new_H->min = H1->min;
	fib_list_concatenate(H1->min, H2->min);
	if (H1->min == NULL || (H2->min != NULL && H2->min->key < H1->min->key))
		new_H->min = H2->min;
	new_H->n = H1->n + H2->n;
	free(H1);
	free(H2);
	return new_H;
}
void fib_heap_link(heap_t *H, node_t *y, node_t *x)
{
	fib_list_delete(H->min, y);

	y->right = x->child->right;
	y->left = x->child;
	x->child->right->left = y;
	x->child->right = y;
	y->parent = x;
	x->degree += y->degree;
	y->mark = false;
}
arr_t degree_list(heap_t *H)
{
	node_t *initial = H->min, *node = initial->right;
	int max = initial->degree;
	while (node != initial)
	{
		if (node->degree > max)
			max = node->degree;
		node = node->right;
	}
	max += 1;
	node_t **arr = (node_t **)malloc(sizeof(node_t *)*max);
	for (int i = 0;i < max;i++)
		arr[i] = NULL;
	return{ max, arr };
}
void consolidate(heap_t *H)
{
	arr_t result_arr = degree_list(H);
	node_t **A = result_arr.start;
	node_t *initial = H->min->left, *node = H->min;
	bool left_shift = false, terminate = false;
	do
	{
		node_t *x = node, *y, *temp;
		if (node == initial && left_shift)
			terminate = true;
		else
			node = node->right;
		degree_t d = x->degree;
		while (A[d] != NULL)
		{
			y = A[d];
			if (x->key > y->key)
			{
				temp = x;
				x = y;
				y = temp;
			}
			if (y == initial && !terminate) //!!!
			{
				initial = initial->left; //!!!
				left_shift = true;
			}
			fib_heap_link(H, y, x);
			A[d] = NULL;
			d += 1;
		}
		A[d] = x;
	} while ((node != initial || left_shift) && !terminate);

	H->min = initial;
	for (int i = 0; i < result_arr.length; i++)
	{
		if (A[i] != NULL && (H->min == NULL || A[i]->key < H->min->key))
			H->min = A[i];
	}
	for (int i = 0; i < result_arr.length; i++)
	{
		free(A[i]);
	}
	//free
}

node_t *fib_heap_extract_min(heap_t *H)
{
	node_t *z = H->min;
	if (z != NULL)
	{
		node_t *node = z->child->right;
		do
		{
			node->parent = NULL;
			node = node->right;
		} while (node != z->child);
		fib_list_concatenate(z, node);
		if (z->right == z)
			H->min = NULL;
		else
		{
			H->min = z->right;
			consolidate(H);
		}
	}
	H->n -= 1;
	return z;
}
void cut(heap_t *H, node_t *x, node_t *y)
{
	fib_list_delete(y->child, x);
	y->degree -= 1;
	fib_list_concatenate(H->min, x);
	x->parent = NULL;
	x->mark = false;
}
void cascading_cut(heap_t *H, node_t *y)
{
	node_t *z = y->parent;
	if (z != NULL)
	{
		if (y->mark == false)
			y->mark = true;
		else
		{
			cut(H, y, z);
			cascading_cut(H, z);
		}
	}
}
bool fib_heap_decrease_key(heap_t *H, node_t *x, key_t key)
{
	if (key > x->key)
	{
		printf("new key is greater than current key", stderr);
		return false;
	}
	x->key = key;
	node_t *y = x->parent;
	if (y != NULL && x->key < y->key)
	{
		cut(H, x, y);
		cascading_cut(H, y);
	}
	if (x->key < H->min->key)
		H->min = x;
	return true;
}
void fib_heap_delete(heap_t *H, node_t *x)
{
	fib_heap_decrease_key(H, x, KEY_MIN);
	fib_heap_extract_min(H);
}
int main(void)
{

	return 0;
}