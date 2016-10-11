#include <stdio.h>
#include <stdbool.h>

int hoare_partition(int A[], int start, int end)
{
	int pivot = A[start];
	int traverse_start = start - 1;
	int traverse_end = end + 1;
	int temp;
	while (true)
	{
		printf("pivot:%d\ntraverse_start:%d\ntraverse_end:%d\n", pivot, traverse_start, traverse_end);
		do
			traverse_end--;
		while (A[traverse_end] > pivot);
		do
			traverse_start++;
		while (A[traverse_start] < pivot);
		if (traverse_start < traverse_end)
		{
			temp = A[traverse_start];
			A[traverse_start] = A[traverse_end];
			A[traverse_end] = temp;
		}
		else
			return traverse_end;
	}
}

void quicksort(int A[], int start, int end)
{
	if (start < end)
	{
		int pivot_index = hoare_partition(A, start, end);
		quicksort(A, start, pivot_index);
		quicksort(A, pivot_index + 1, end);
	}
}

int main(void)
{
	int A[12] = { 13,16,18,5,9,0,5,4,20 };
	quicksort(A, 0, 8);
	for (int i = 0; i < 8; i++)
		printf("%d  ", A[i]);
	return 0;
}