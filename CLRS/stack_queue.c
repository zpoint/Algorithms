#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int *arr;
	int maxlength;
	int top = -1;
}stack;

typedef struct
{
	int *arr;
	int maxlength;
	int top = maxlength;
}stack_reverse;

typedef struct
{
	int *arr;
	int maxlength;
	int head = 0;
	int tail = 0;
	int queue_length = 0;
}queue;

int top(stack st)
{
	return st.top;
}

bool stack_empty(stack st)
{
	if (st.top < 0)
		return true;
	else
		return false;
}

bool push(stack st, int val)
{
	if (st.top + 1 > st.maxlength)
	{
		fprintf(stderr, "Stack Overflow!");
		exit(0);
	}
	st.top += 1;
	st.arr[st.top] = val;
	return true;
}

int pop(stack st)
{
	if (st.top < 0)
	{
		fprintf(stderr, "Stack Underflow!");
		exit(0);
	}
	int return_val = st.arr[st.top];
	st.top -= 1;
	return return_val;
}

void enqueue_last(queue *ptr_q, int x)
{
	if (ptr_q->queue_length + 1 >= ptr_q->maxlength) { fprintf(stderr, "Queue Overflow!\n"); exit(0); }
	ptr_q->arr[ptr_q->tail] = x;
	if (ptr_q->tail == ptr_q->maxlength - 1)
		ptr_q->tail = 0;
	else
		ptr_q->tail += 1;
	ptr_q->queue_length += 1;
}

void enqueue_first(queue *ptr_q, int val)
{
	if (ptr_q->queue_length >= ptr_q->maxlength - 1)
	{
		fprintf(stderr, "Queue overflow, enqueue_first");
		exit(0);
	}
	int prev_head = ptr_q->head == 0 ? ptr_q->maxlength - 1 : ptr_q->head - 1;
	ptr_q->arr[prev_head] = val;
	ptr_q->head = prev_head;
	ptr_q->queue_length += 1;
}

int dequeue_last(queue *ptr_q)
{
	if (ptr_q->queue_length - 1 < 0)
	{
		fprintf(stderr, "Queue Underflow, dequeue last");
		exit(0);
	}
	int return_value = ptr_q->arr[ptr_q->tail];
	if (ptr_q->tail == 0)
	{
		ptr_q->tail = ptr_q->maxlength - 1;
	}
	else
		ptr_q->tail -= 1;
	ptr_q->queue_length -= 1;
	return return_value;
}

int dequeue_first(queue *ptr_q)
{
	if (ptr_q->queue_length - 1 < 0)
	{
		fprintf(stderr, "Queue Underflow!\n");
		exit(0);
	}

	int return_value = ptr_q->arr[ptr_q->head];
	if (ptr_q->head == ptr_q->maxlength - 1)
	{
		ptr_q->head = 0;
	}
	else
		ptr_q->head += 1;
	ptr_q->queue_length -= 1;
	return return_value;

}

int main(void)
{
	int arr[5] = { 0,0,0,0,0 };
	int size = sizeof(arr) / sizeof(int);
	queue q;
	q.arr = arr;
	q.maxlength = size;
	enqueue_first(&q, 3);
	enqueue_first(&q,4);
	enqueue_first(&q, 3);
	enqueue_first(&q, 4);
	dequeue_last(&q);
	dequeue_last(&q);
	dequeue_last(&q);
	dequeue_last(&q);
	dequeue_last(&q);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}