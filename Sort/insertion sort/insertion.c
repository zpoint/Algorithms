#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 150

void insertion_sort(int *arr, int size)
{
		int tmp, j;
		if (size > 1)
		{
				for (int i = 1; i < size; i++)
				{
						j = i - 1;
						while (arr[j] > arr[j + 1] && j >= 0)
						{
								tmp = arr[j];
								arr[j] = arr[j + 1];
								arr[j + 1] = tmp;
								--j;
						}
				}
		}
}

void pr_arr(int *arr, const char *str, int size)
{
		printf("\n\t\tsize: %d, %s\n\t\t", size, str);
		for (int i = 0; i < size; i++)
		{
				printf("%3d ", arr[i]);
				if (i != 0 && i % 10 == 0)
						printf("\n\t\t");
		}
		printf("\n");
}

int main(void)
{
		srand(time(NULL));
		int arr[SIZE];
		for (int i = 0; i < SIZE; i++)
				arr[i] = rand() % 10;
		pr_arr(arr, "Iinitialized", SIZE);
		insertion_sort(arr, SIZE);
		pr_arr(arr, "After Insertion sort", SIZE);
		return(0);
}
