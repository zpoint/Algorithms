#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// implementation with array
typedef int value_t;
typedef unsigned int msize_t; // my size type, (maybe long or long long in 32 bit machine)
#define SIZE 16 // initial size
#define VERR 1 << 31 // define a value not going be used to determine error
typedef struct PQ
{
		msize_t length;
		msize_t capacity;
		value_t *arr;
}pq_t;

pq_t *init_pq(void)
{
		pq_t *new_pq;
		value_t *new_arr;
		if ((new_pq = (pq_t *)malloc(sizeof(pq_t))) == NULL)
				{fprintf(stderr, "malloc error in init)pq"); return(NULL);}
		if ((new_arr = (value_t *)malloc(sizeof(value_t) * SIZE)) == NULL)
				{fprintf(stderr, "malloc error in init_pq"); return(NULL);}
		memset(new_arr, 0, sizeof(value_t) * SIZE);
		new_pq->length = 0;
		new_pq->capacity = SIZE;
		new_pq->arr = new_arr;
		return(new_pq);
}

void resize(pq_t *pq_ptr, msize_t new_size)
{
		if (new_size <= 0)
				{fprintf(stderr, "err in resize"); exit(0);}
		if ((pq_ptr->arr = (value_t *)realloc(pq_ptr->arr, sizeof(value_t) * new_size)) == NULL)
				{fprintf(stderr, "err in resize(realloc)"); exit(0);}
		pq_ptr->capacity = new_size;
		if (pq_ptr->length > new_size)
				pq_ptr->length = new_size;
}

value_t pq_findmin(pq_t *pq_ptr)
{
		if (pq_ptr->length == 0)
				{fprintf(stderr, "Queue length is 0, find err"); return(VERR);}
		return(pq_ptr->arr[0]);
}

value_t pq_insert(pq_t *pq_ptr, value_t val)
{
		value_t tmp;
		if (pq_ptr->length == pq_ptr->capacity)
				resize(pq_ptr, 2 * pq_ptr->capacity);
		if (pq_ptr->length == 0)
				pq_ptr->arr[0] = val;
		else if ((tmp = pq_findmin(pq_ptr)) > val)
		{       // insert a new min value
				pq_ptr->arr[0] = val;
				pq_ptr->arr[pq_ptr->length] = tmp;
		}
		else
				pq_ptr->arr[pq_ptr->length] = val;
		pq_ptr->length++;
		return(val);
}

value_t pq_deletemin(pq_t *pq_ptr)
{
		value_t min_val, tmp_val;
		msize_t min_index;
		if (pq_ptr->length == 0)
				{fprintf(stderr, "Delete an empty queue"); exit(0);}
		if (pq_ptr->length == 1)
		{
				pq_ptr->length -= 1;
				return(pq_ptr->arr[0]);
		}
		// >= 2 values in queue
		min_val = pq_ptr->arr[1];
		min_index = 1;
		for (msize_t i = 1; i < pq_ptr->length; i++)
		{
				if (pq_ptr->arr[i] < min_val)
				{
						min_val = pq_ptr->arr[i];
						min_index = i;
				}
		}
		tmp_val = min_val;
		pq_ptr->arr[min_index] = pq_ptr->arr[pq_ptr->length - 1];
		pq_ptr->arr[pq_ptr->length - 1] = min_val;
		tmp_val = pq_ptr->arr[0];
		pq_ptr->arr[0] = pq_ptr->arr[pq_ptr->length - 1];
		pq_ptr->length--;
		if (pq_ptr->length < pq_ptr->capacity / 4)
				resize(pq_ptr, pq_ptr->capacity / 2);
		return(tmp_val);
}

void pr_pq(pq_t *pq_ptr, const char *str)
{
		printf("\t\t%s\n\t\tcapacity: %d, length: %d, pq_findmin: %d\n\t\t", str, pq_ptr->capacity, pq_ptr->length, pq_findmin(pq_ptr));
		for (msize_t i = 0; i < pq_ptr->length; i++)
		{
				printf("%d:%d\t", i, pq_ptr->arr[i]);
				if (i != 0 && i % 10 == 0)
						printf("\n\t\t");
		}
		printf("\n");
}

int main(void)
{
		pq_t *queue = init_pq();
		pr_pq(queue, "After initialized");
		for (value_t i = 100; i > 0; i--)
				pq_insert(queue, i);
		pr_pq(queue, "After insert value 100 to 1:");
		for (value_t i = 0; i < 30; i++)
				pq_deletemin(queue);
		pr_pq(queue, "Call deletemin 30 times");
		return(0);
}
