#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PARENT(i) ((i+1)/2-1)
#define LEFT(i) (2*(i+1)-1)
#define RIGHT(i) (2*(i+1))
#define VERR 1 << 31
#define VMAX 1 << 31 ^ (-1)
#define VMIN 1 << 31
typedef int val_t;

typedef struct Pheap_t
{
		val_t *arr;
		int size;
		int capacity;
}pheap_t;

int sift_up(pheap_t *heap, int index)
{
		if (index >= heap->size)
				return(0);
		val_t parent, curr;
		while (index != 0)
		{
				parent = heap->arr[PARENT(index)];
				if ((curr = heap->arr[index]) > parent)
				{
						heap->arr[index] = parent;
						heap->arr[PARENT(index)] = curr;
						index = PARENT(index);
				}
				else
						break;
		}
		return(1);
}

int sift_down(pheap_t *heap, int index)
{
		if (index >= heap->size)
				return(0);
		int left_index, right_index, max_index;
		val_t tmp;
		while (index < heap->size)
		{
				max_index = index;
				left_index = LEFT(index);
				right_index = RIGHT(index);
				if (left_index <= heap->size && heap->arr[left_index] > heap->arr[max_index])
						max_index = left_index;
				if (right_index <= heap->size && heap->arr[right_index] > heap->arr[max_index])
						max_index = right_index;
				if (max_index == index)
						break;
				else
				{
						tmp = heap->arr[index];
						heap->arr[index] = heap->arr[max_index];
						heap->arr[max_index] = tmp;
						index = max_index;
				}
		}
		return(1);
}

val_t get_max(pheap_t *heap)
{
		if (heap->size == 0)
				return(VERR);
		return(heap->arr[0]);
}

int get_size(pheap_t *heap)
{
		return(heap->size);
}

int is_empty(pheap_t *heap)
{
		if (get_size(heap) == 0)
				return(1);
		return(0);
}

val_t extract_max(pheap_t *heap)
{
		if (heap->size == 0)
				return(VERR);
		val_t max = heap->arr[0];
		heap->arr[0] = heap->arr[heap->size - 1];
		--heap->size;
		sift_down(heap, 0);
		/*
		if (heap->size < heap->capacity / 4)
		{
				heap->arr = realloc(heap->arr, sizeof(val_t) * (heap->capacity / 4));
				heap->capacity /= 4;
		}
		*/
		return(max);
}

val_t remov_heap(pheap_t *heap, int index)
{
		if (index >= heap->size || index < 0)
				return(VERR);
		val_t ret_val = heap->arr[index];
		heap->arr[index] = VMAX;
		sift_up(heap, index);
		extract_max(heap);
		return(ret_val);
}

int insert(pheap_t *heap, val_t value)
{
		if (heap->size == heap->capacity)
		{
				heap->arr = realloc(heap->arr, sizeof(val_t) * (2 * heap->capacity));
				heap->capacity *= 2;
		}
		heap->arr[heap->size++] = value;
		sift_up(heap, heap->size-1);
		return(1);
}

int heapify(pheap_t *heap)
{
		if (heap->size == 0)
				return(0);
		for (int i = PARENT(heap->size - 1); i >= 0; i--)
				sift_down(heap, i);
		return(1);
}

int heap_sort(pheap_t *heap)
{
		// in place
		if (heap->size == 0)
				return(0);
		for (int i = heap->size - 1; i >= 0; i--)
		{
				heap->arr[i] = extract_max(heap);
		}
		return(1);
}

pheap_t *init_heap()
{
		pheap_t *heap = malloc(sizeof(pheap_t));
		heap->size = 0;
		heap->arr = malloc(sizeof(val_t));
		heap->capacity = 1;
		return(heap);
}

void pr_heap(pheap_t *heap)
{
		printf("\n\t\t");
		for (int i = 1; i <= heap->size; i++)
		{
				printf("%d\t", heap->arr[i-1]);
				if (i % 10 == 0)
						printf("\n\t\t");
		}
		printf("\n");
}

int main(int argc, char *argv)
{
		srand(time(NULL));
		val_t *arr = malloc(sizeof(int) * 100);
		for (int i = 0; i < 100; i++)
				arr[i] = rand() % 100;
		pheap_t *heap = malloc(sizeof(heap));
		heap->size = 100;
		heap->arr = arr;
		heap->capacity = 100;
		printf("\t\tAfter generate 100 random numbers between 0 - 99\n");
		pr_heap(heap);
		printf("\t\t After heapify\n");
		heapify(heap);
		pr_heap(heap);
		printf("\t\t After heap_sort\n");
		heap_sort(heap);
		heap->size = 100;
		pr_heap(heap);
		return(0);
}

