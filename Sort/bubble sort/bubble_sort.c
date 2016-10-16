#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 160
void pr_arr(int *, int, const char*);

void bubble_sort(int *arr, int size)
{
		int temp;
		for (int i = 0; i < size - 1; i++)
		{
				for (int j = 0; j < size - i - 1; j++)
				{
						if (arr[j] > arr[j + 1])
						{
								temp = arr[j];
								arr[j] = arr[j + 1];
								arr[j + 1] = temp;
						}
				}
		}
}

void pr_arr(int *arr, int size, const char *str)
{
		printf("\n\t\tsize: %d, %s\n\t\t", size, str);
		for (int i = 0; i < size; i++)
		{
				printf("%-3d  ", arr[i]);
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
				arr[i] = rand() % 100;
		pr_arr(arr, SIZE, "Initialized with 1-100 random value");
		printf("\t\tNow bubble sort");
		bubble_sort(arr, SIZE);
		pr_arr(arr, SIZE, "After bubble sort");
		return(0);
}
