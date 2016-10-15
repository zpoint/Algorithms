#include <stdio.h>
#include <stdlib.h>

typedef int msize_t;
typedef int value_t;

typedef struct Node_t
{
		struct Node_t *prev;
		struct Node_t *next;
		value_t val;
}node_t;

typedef struct QE_t
{
		struct Node_t *head;
		struct Node_t *tail;
		msize_t size;
}qe_t;

qe_t *init_queue(void)
{
		qe_t *q_ptr = (qe_t *)malloc(sizeof(qe_t));
		q_ptr->head = NULL;
		q_ptr->tail = NULL;
		q_ptr->size = 0;
		return(q_ptr);
}

void enqueue(qe_t *q_ptr, value_t val)
{
		node_t *node_ptr = (node_t *)malloc(sizeof(node_t));
		node_ptr->prev = NULL;
		node_ptr->next = NULL;
		node_ptr->val = val;
		if (q_ptr->head == NULL)
		{
				q_ptr->head = node_ptr;
				q_ptr->tail = node_ptr;
		}
		else
		{
				node_ptr->prev = q_ptr->tail;
				q_ptr->tail->next = node_ptr;
				q_ptr->tail = node_ptr;
		}
		q_ptr->size++;
}

void dequeue(qe_t *q_ptr)
{
		if (q_ptr->size == 0)
				{ fprintf(stderr, "Dequeue err, size 0"); exit(0); }
		node_t *tmp = q_ptr->tail;
		q_ptr->tail = q_ptr->tail->prev;
		q_ptr->size--;
		free(tmp);
}

int empty(qe_t *q_ptr)
{
	return(q_ptr->size == 0 ? 1 : 0);
}

void pr_queue(qe_t *q_ptr, const char *str)
{
		node_t *tmp = q_ptr->head;
		printf("\t\t%s empty?: %d size: %d\n\t\t", str, empty(q_ptr), q_ptr->size);
		for (msize_t i = 0; i < q_ptr->size; i++)
		{
				printf("%d: %d\t", i, tmp->val);
				if (i % 10 == 0 && i != 0)
						printf("\n\t\t");
				tmp = tmp->next;
		}
		putchar('\n');
}

int main(void)
{
		qe_t *queue = init_queue();
		pr_queue(queue, "Queue initialized");
		for (msize_t i = 0; i < 100; i++)
				enqueue(queue, i);
		pr_queue(queue, "Enqueue 1 -- 100");
		for (msize_t i = 0; i < 50; i++)
				dequeue(queue);
		pr_queue(queue, "Dequeue 50 times");
		return(0);
}
