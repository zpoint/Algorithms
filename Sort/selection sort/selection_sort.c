#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 150

void selection_sort(int *arr, int size)
{
		int min, min_index;
		for (int i = 0; i < size; i++)
		{
				min = arr[i];
				min_index = i;
				for (int j = i + 1; j < size; j++)
				{
						if (arr[j] < min)
						{
								min = arr[j];
								min_index = j;
						}
				}
				if (min_index != i)
				{
						arr[min_index] = arr[i];
						arr[i] = min;
				}
		}
}

void pr_arr(int *arr, int size, const char *str)
{
		printf("\n\t\tsize: %d, %s\n\t\t", size, str);
		for (int i = 1; i < size + 1; i++)
		{
				printf("%3d ", arr[i - 1]);
				if (i % 10 == 0)
						printf("\n\t\t");
		}
		printf("\n");
}

int main(int argc, char *argv[])
{
		int arr[SIZE];
		srand(time(NULL));
		for (int i = 0; i < SIZE; i++)
				arr[i] = rand() % 100;
		pr_arr(arr, SIZE, "After Initialized");
		selection_sort(arr, SIZE);
		pr_arr(arr, SIZE, "Calling selection_sort:");
		return(0);
}
