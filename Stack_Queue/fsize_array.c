#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef int msize;
typedef int value_t;
#define VERR -1

typedef struct QE_t
{
		msize start;
		msize end;
		value_t *arr;
		msize capacity;
}qe_t;

void pr_queue(qe_t *, const char *);
qe_t *init_queue(void)
{
		qe_t *q_ptr = (qe_t *)malloc(sizeof(qe_t));
		q_ptr->arr = (value_t *)malloc(sizeof(value_t) * SIZE);
		memset(q_ptr->arr, 0, sizeof(value_t) * SIZE);
		q_ptr->start = 0;
		q_ptr->end = 0;
		q_ptr->capacity = SIZE;
		return(q_ptr);
}

// In the pointer-based implementation strategy, the buffer's full or empty state can be resolved from the start and end indexes. When they are equal, the buffer is empty, and when the start is one greater than the end, the buffer is full
int enqueue(qe_t *q_ptr, value_t val)
{
		if (q_ptr->end == (q_ptr->capacity - 1))
		{
				if (q_ptr->start == 0)
						{ printf("\n\t\t%d:", val); fprintf(stderr, "enqueue fail, full"); return(0);}
				q_ptr->arr[0] = val;
				q_ptr->end = 0;
				return(1);
		}
		else
		{
				if (q_ptr->end + 1 == q_ptr->start)
						{fprintf(stderr, "enqueue fail, full"); return(0); }
				q_ptr->arr[++q_ptr->end] = val;
		}
}


value_t dequeue(qe_t *q_ptr)
{
		value_t tmp = q_ptr->arr[q_ptr->end];
		if (q_ptr->start == q_ptr->end)
				{	fprintf(stderr, "dequeue fail, empty"); return(VERR); }
		else if (q_ptr->end == 0)
				q_ptr->end = q_ptr->capacity - 1;
		else
				q_ptr->end -= 1;
		return(tmp);
}

int full(qe_t *q_ptr)
{
		if ((q_ptr->end == (q_ptr->capacity - 1) && q_ptr->start == 0) || 
			( q_ptr->start == q_ptr->end + 1))
				return(1);
		return(0);
}

int empty(qe_t *q_ptr)
{
		if (q_ptr->start == q_ptr->end)
				return(1);
		return(0);
}

void pr_queue(qe_t *q_ptr, const char *str)
{
		printf("\t\tstart: %d, end: %d, empty: %d, full: %d, %s\n\t\t", q_ptr->start, q_ptr->end, empty(q_ptr), full(q_ptr), str);
		for (msize i = 0; i < q_ptr->capacity; i++)
		{
				if (q_ptr->end < q_ptr->start && (i > q_ptr->end && i < q_ptr->start) || (q_ptr->end > q_ptr->start) && (i > q_ptr->start && i < q_ptr->end))
						printf("X \t");
				else
						printf("%d\t", q_ptr->arr[i]);
				if (i != 0 && i % 10 == 0)
						printf("\n\t\t");
		}
		printf("\n");
}


int main(void)
{
		qe_t *queue = init_queue();
		pr_queue(queue, "initialized");
		for (msize i = 0; i < 19; i++)
			enqueue(queue, i + 1);
		pr_queue(queue, "enqueue 1 - 19");
		for (msize i = 0; i < 10; i++)
				dequeue(queue);
		pr_queue(queue, "dequeue 10 times");
		return(0);
}
