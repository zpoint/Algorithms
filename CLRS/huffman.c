//Not yet finished, need
/*typedef struct node_heap
{
	node_t *A[];
	int size;
}
then, modify the code
*/
#include <stdio.h>
#include <stdlib.h>
#define PARENT(i) i/2
#define LEFT(i) 2 * i
#define RIGHT(i) 2 * i + 1
typedef struct tree_node
{
	tree_node *parent;
	tree_node *left;
	tree_node *right;
	int key;
}node_t;
void min_heapify(node_t *A[], int i, int size)
{
	int left = LEFT(i), right = RIGHT(i), minimum;
	node_t *temp = NULL;
	if (left <= size && A[left]->key < A[i]->key)
		minimum = left;
	else
		minimum = i;
	if (right <= size && A[right]->key < A[i]->key)
		minimum = right;
	if (minimum != i)
	{
		temp = A[i];
		A[i] = A[minimum];
		A[minimum] = temp;
		min_heapify(A, minimum, size);
	}
}
void build_min_heap(node_t *A[], int size)
{
	for (int i = size / 2;i >= 1;i++)
		min_heapify(A, i, size);
}
node_t *heap_extract_min(node_t *A[], int size)
{
	if (size < 1)
		printf("heap underflow\n", stderr);
	node_t *min_ptr = A[0];
	A[0] = 
}
/*
int partition(int A[], int start_index, int stop_index)
{
	int pivot = A[stop_index], i = start_index - 1, temp;
	for (int j = start_index;j < stop_index - 1;j++)
	{
		if (A[j] <= pivot)
		{
			i += 1;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	A[stop_index] = A[i + 1];
	A[i + 1] = pivot;
	return i + 1;
}
int *quicksort(int A[], int start_index, int stop_index)
{
	if (start_index < stop_index)
	{
		int mid_index = partition(A, start_index, stop_index);
		quicksort(A, start_index, mid_index - 1);
		quicksort(A, mid_index + 1, stop_index);
	}
}
*/
void huffman(node_t *A[], int size)
{
	build_min_heap(A, size);
	for (int i = 1; i < size; i++)
	{
		node_t *new_node = (node_t *)malloc(sizeof(node_t));
		new_node->left = heap_extract_min(A, size);
		new_node->right = heap_extract_min(A, size);
		new_node->key = new_node->left->key + new_node->right->key;
		insert(A, new_node);
	}
	return heap_extract_min(A, size);
}
int main(void)
{
	
	return 0;
}