#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 150

int *merge(int *arrL, int *arrR, int lsize, int rsizre)
{
		int total = lsize + rsizre; 
		int indexL = 0; int indexR = 0;
		int *new_arr = malloc(sizeof(int) * (lsize + rsizre));
		for (int i = 0; i < total; i++)
		{
				if (indexL >= lsize)
						new_arr[i] = arrR[indexR++];
				else if (indexR >= rsizre)
						new_arr[i] = arrL[indexL++];
				else
				{
						if (arrL[indexL] < arrR[indexR])
								new_arr[i] = arrL[indexL++];
						else
								new_arr[i] = arrR[indexR++];
				}
		}
		free(arrL);
		free(arrR);
		return(new_arr);
}


int *merge_sort(int *arr, int size)
{
		// Initial Caller should call free
		if (size == 1)
		{
				int *new_arr = (int *)malloc(sizeof(int));
				new_arr[0] = arr[0];
				return(new_arr);
		}
		int lsize = size / 2;
		int rsizre = size - lsize;
		int *arrL = merge_sort(arr, lsize);
		int *arrR = merge_sort(arr + lsize, rsizre);
		int *new_arr = merge(arrL, arrR, lsize, rsizre);
		return(new_arr);
}

void pr_arr(int *arr, int length, const char *str)
{
		printf("\n\t\tsize: %d, %s\n\t\t", length, str);
		for (int i = 0; i < length; i++)
		{
				printf("%3d ", arr[i]);
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
		pr_arr(arr, SIZE, "Initial!!!");
		pr_arr(merge_sort(arr, SIZE), SIZE, "After merge_sort");
}
