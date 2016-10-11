#include <stdio.h>
#include <stdlib.h>
void counting_sort(int* array_unsorted, int* return_array, int max_value, int lenth_array)
{
	int* array_temp = (int *)malloc(sizeof(int) * (max_value + 1)),
		i;
	for (i = 0; i <= max_value; i++)
		array_temp[i] = 0;
	for (i = 0; i < lenth_array; i++)
		array_temp[array_unsorted[i]] = array_temp[array_unsorted[i]] + 1;
	for (i = 1; i <= max_value; i++)
		array_temp[i] += array_temp[i - 1];
	for (i = 0; i < lenth_array; i++)
	{
		return_array[array_temp[array_unsorted[i]] - 1] = array_unsorted[i];
		array_temp[array_unsorted[i]]--;
	}

	free(array_temp);
}
int mian(void)
{
	int A[8] = { 2,5,3,0,2,3,0,3 };
	const int SIZE = sizeof(A) / 4;
	int B[SIZE] = { 0 };
	counting_sort(A, B, 5, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d  ", A[i]);
	printf("\n");
	return 0;
}