#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void show_result(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	printf("%d ", arr[i]);
	printf("\n");
}

void insertion_sort_nonincreasing(int *arr,int length)
{
	//2.1-2
	for (int j = 1; j < length; j++)
	{
		int key = *(arr + j), i = j - 1;
		while (i >= 0 && arr[i] < key)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}

int liner_search(int *arr,int length,int v)
{
	//2.1-3
	for (int i = 0;i < length;i++)
	{
		if (arr[i] == v)
			return i + 1;
	}
	return -1;
}

int *selection_sort(int *arr, int length)
{
	//2.2-2
	int temp;//for exchange
	for (int i = 0;i < length - 1;i++)
	{
		int min = arr[i], j_num = i;
		for (int j = i + 1;j < length;j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				j_num = j;
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[j_num] = temp;
	}
	return arr;
}

void merge(int *arr, int left, int middle, int right)
{
	int left_length = middle - left + 1;
	int right_length = right - middle;
	int *L = (int *)malloc(sizeof(int) * left_length);
	int *R = (int *)malloc(sizeof(int) * right_length);
	int i, j = 0;
	for (i = 0; i < left_length; i++)
		L[i] = arr[left + i];
	for (i = 0; i < right_length; i++)
		R[i] = arr[middle + i + 1];
	i = 0;//j = 0;
	//show_result(L, left_length);
	//show_result(R, right_length);
	for (int k = left; k <= right; k++)
	{
		if (i >= left_length)
		{
			arr[k] = R[j];
			j += 1;
		}
		else if (j >= right_length)
		{
			arr[k] = L[i];
			i += 1;
		}
		else if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i += 1;
		}
		else
		{
			arr[k] = R[j];
			j += 1;
		}
	}
	free(L);
	free(R);
}
void merge_sort(int *arr, int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
}

int binary_search(int *arr, int length, int v)
{
	int low = 0;
	int height = length;
	int mid;
	while (low <= height)
	{
		mid = (low + height) / 2;
		if (arr[mid] == v)
			return true;
		else if (arr[mid] < v)
			low = mid + 1;
		else
			height = mid - 1;
	}
	return false;
}

/*********************************************
* heap functions including heap_max
********************************************/
void max_heapify(int *arr, int i, int length)
{
	// i = 1,2,3,4,5....i
	//arr[0],arr[1],arr[2]...arr[i - 1]
	int largest, temp;
	int l = 2 * i - 1;
	int r = l + 1;
	i -= 1;
	if (l <= length - 1 && arr[l] > arr[i])
		largest = l;
	else
		largest = i;
	
	if (r <= length - 1 && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr, largest + 1, length);
	}
}

void max_heapify_loop_version(int *arr, int i, int length)
{
	int largest, temp;
	int l = 2 * i - 1;
	int r = l + 1;
	i -= 1;
	if (l < length && arr[l] > arr[i])
		largest = l;
	else
		largest = i;
	if (r <= length && arr[r] > arr[largest])
		largest = r;
	while (largest != i)
	{
		//exchange
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		//key point
		i = largest + 1;
		//done
		//repeat
		l = 2 * i - 1;
		r = l + 1;
		i -= 1;
		if (l < length && arr[l] > arr[i])
			largest = l;
		else
			largest = i;
		if (r <= length && arr[r] > arr[largest])
			largest = r;
	}
}

void min_heapify(int *arr, int i, int length)
{
	//i = 1,2,3,4,5...i
	//arr[0], arr[1], arr[2]...arr[i - 1]
	int minimum, temp;
	int l = 2 * i - 1;
	int r = 1 + l;
	i -= 1;
	if (l < length && arr[l] < arr[i])
		minimum = l;
	else
	{
		minimum = i;
	}

	if (r < length && arr[r] < arr[minimum])
		minimum = r;
	if (minimum != i)
	{
		temp = arr[i];
		arr[i] = arr[minimum];
		arr[minimum] = temp;
		min_heapify(arr, minimum + 1, length);
	}
}

void build_max_heap(int *arr, int length)
{
	for (int i = length / 2 - 1;i >= 0;i--)
		max_heapify(arr,i + 1,length);
}

void heapsort(int *arr, int length)
{
	int temp;
	for (int i = length - 1;i > 0;i--)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		max_heapify(arr, 1, i);
	}
}

int heap_maximum(int *arr)
{
	return arr[0];
}

int heap_extract_max(int *arr, int *length)
{
	if (*length < 1)
		fprintf(stderr, "heap underflow,function: heap_extract_max\n");
	//ecchange arr[0] and arr[length - 1]
	int max = arr[0];
	arr[0] = arr[*length - 1];
	*length -= 1;
	max_heapify(arr, 1, *length);
	return max;
}

void heap_increase_key(int *arr, int i, int key)
{
	//In my standard, i start from 1, so i = 1,2,3,4...n
	//i = 1 implies arr[0]
	if (key < arr[i - 1])
		fprintf(stderr, "function:heap_increase_key \nnew key is smaller than current key\n new key:%d\ncurrent key:%d\n", key, arr[i - 1]);
	int temp;
	arr[i - 1] = key;
	while (i > 1 && arr[i / 2 - 1] < arr[i - 1])
	{
		temp = arr[i / 2 - 1];
		arr[i / 2 - 1] = arr[i - 1];
		arr[i - 1] = temp;
		i = i / 2;
	}
}

void max_heap_insert(int *arr, int key, int *length)
{
	*length += 1;
	arr = (int *)realloc(arr, sizeof(int) * (*length)); 
	arr[*length] = 1 << 31; // int minimun value
	heap_increase_key(arr, *length, key);

}

/*********************************************
* heap_min functions
********************************************/
int meap_minimum(int *arr)
{
	return arr[0];
}

int heap_extract_min(int *arr, int *length)
{
	if (*length < 1)
		fprintf(stderr, "heap underflow function:heap_extract_min\n");
	int min = arr[0];
	*length -= 1;
	arr[0] = arr[*length];
	arr[*length] = min;
	min_heapify(arr, 1, *length);
	return min;

}

void heap_decrease_key(int *arr, int i, int key, int length)
{
	//In my standard, i start from 1, so i = 1,2,3,4...n
	//i = 1 implies arr[0]
	if (key > arr[i - 1])
		fprintf(stderr, "new key is bigger than current key\nIn function heap_decrease_key\nnew_key:%d\ncurrent_key:%d\n", key, arr[0]);
	int temp;
	arr[i - 1] = key;
	while (i > 1 && arr[i / 2 - 1] > key)
	{
		temp = arr[i / 2 - 1];  //parent
		arr[i / 2 - 1] = key;   
		arr[i - 1] = temp;
		i = i / 2;
	}
}

void min_heap_insert(int *arr, int key, int *length)
{
	arr = (int *)realloc(arr, sizeof(int) * (++*length));
	//It has problem in Visual Studio C++, the address value arr will be changed when this function return
	//Though it's good in linux with gcc 
	arr[*length - 1] = ~(1 << 31);
	heap_decrease_key(arr, *length, key, *length);
}



int main(void)
{
	int *arr = (int *)malloc(sizeof(int) * 7);
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 5;
	arr[4] = 6;
	arr[5] = 7;
	arr[6] = 9;
/*	arr[7] = 2;
	arr[8] = 4;
	arr[9] = 1;
	arr[10] = 2;
	arr[11] = 1;
*/
	int size = 7;
	min_heap_insert(arr, 2, &size);
	show_result(arr, size);
	return 0;
}
