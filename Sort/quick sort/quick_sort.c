#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 150

void pr_arr(int *, int, const char *);
int partition(int *arr, int start_index, int stop_index)
{
		srand(time(NULL));
		int pivot, pivot_index, tmp;
		// return pivot index
		if (start_index == stop_index)
				return(start_index);
		pivot_index = rand() % (stop_index - start_index + 1);
		pivot = arr[pivot_index + start_index];
		while (start_index != stop_index)
		{
				while (arr[start_index] < pivot /*&& start_index < stop_index*/)
						start_index++;
				while (arr[stop_index] > pivot /*&& stop_index > start_index*/)
						stop_index--;
				if (arr[start_index] == pivot && arr[stop_index] == pivot && start_index != stop_index)
				{
						stop_index--;
						continue;
				}
				tmp = arr[start_index];
				arr[start_index] = arr[stop_index];
				arr[stop_index] = tmp;
		}
		return(start_index);
}

void quick_sort(int *arr, int start_index, int stop_index)
{
		int middle_index = partition(arr, start_index, stop_index);
		int len_left = middle_index - start_index;
		int len_right = stop_index - middle_index;
		if (len_left > 1)
				quick_sort(arr, start_index, middle_index - 1);
		if (len_right > 1)
				quick_sort(arr, middle_index + 1, stop_index);
}

void pr_arr(int *arr, int size, const char *str)
{
		printf("\n\t\tsize: %d, %s\n\t\t", size, str);
		for (int i = 1; i <= size; i++)
		{
				printf("%3d ", arr[i - 1]);
				if (i % 10 == 0)
						printf("\n\t\t");
		}
		printf("\n\t\t");
}

int main(int argc, char *argv)
{
		int arr[SIZE];
		srand(time(NULL));
		for (int i = 0; i < SIZE; i++)
				arr[i] = rand() % 100;
		pr_arr(arr, SIZE, "After initialized");
		quick_sort(arr, 0, SIZE - 1);
		pr_arr(arr, SIZE, "After quicksort");
		return(0);
}
