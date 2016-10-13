#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int msize_t; // mysize
typedef int value_t; // my data type inside a list structure
#define VERR 1 << 31 // define initial/error value of value_t, assume int max not used
#define SIZERR -1 // err size value

typedef struct Node_t
{
		struct Node_t *next;
		struct Node_t *prev;
		value_t value;
}node_t;

typedef struct List_t
{
		struct Node_t *head;
		struct Node_t *tail;
		msize_t size;
}list_t;

node_t *init_node(value_t value)
{
		node_t *n_ptr = (node_t *)malloc(sizeof(node_t));
		if (n_ptr == NULL) { printf("malloc error\n"); exit(0); }
		n_ptr->next = NULL;
		n_ptr->prev = NULL;
		n_ptr->value = value;
		return(n_ptr);
}

node_t *node_at(list_t *l_ptr, msize_t index)
{
		//caller check index before calling node_at
		msize_t i;
		node_t *tmp = l_ptr->head;
		if (index < l_ptr->size / 2)
		{
				tmp = l_ptr->head;
				for (i = 0; i < index; i++)
						tmp = tmp->next;
		}
		else if (index > l_ptr->size / 2)
		{
				tmp = l_ptr->tail;
				for (i = l_ptr->size; i > index; i--)
						tmp = tmp->prev;
		}
		return(tmp);

}

msize_t size(list_t *l_ptr)
{
		return(l_ptr->size);
}

int empty(list_t *l_ptr)
{
		// return 1 True, 0 false
		return(l_ptr->size == 0 ? 1 : 0);
}

value_t value_at(list_t *l_ptr, msize_t index)
{
		if (index >= l_ptr->size)
				return(VERR);
		node_t *n_ptr = node_at(l_ptr, index);
		return(n_ptr->value);
}

void push_front(list_t *l_ptr, value_t value)
{
		node_t *new_nptr = init_node(value);
		if (l_ptr->size == 0)
				l_ptr->head = l_ptr->tail = new_nptr;
		else
		{
				l_ptr->head->prev = new_nptr;
				new_nptr->next = l_ptr->head;
				l_ptr->head = new_nptr;
		}
		l_ptr->size++;
}

value_t pop_front(list_t *l_ptr)
{
		node_t *tmp;
		value_t val;
		if (l_ptr->size == 0)
				return(VERR);
		val = l_ptr->head->value;
		if (l_ptr->size == 1)
		{
				free(l_ptr->head);
				l_ptr->head = l_ptr->tail = NULL;
		}
		else
		{
				tmp = l_ptr->head->next;
				tmp->prev = NULL;
				free(l_ptr->head);
				l_ptr ->head = tmp;
		}
		l_ptr->size--;
		return(val);
}

void push_back(list_t *l_ptr, value_t val)
{
		node_t *new_nptr = init_node(val);
		if (l_ptr->size == 0)
				l_ptr->head = l_ptr->tail = new_nptr;
		else
		{
				l_ptr->tail->next = new_nptr;
				new_nptr->prev = l_ptr->tail;
				l_ptr->tail = new_nptr;
		}
		l_ptr->size++;
}

value_t pop_back(list_t *l_ptr)
{
		if (l_ptr->size == 0)
				return(VERR);
		node_t *tmp;
		value_t val = l_ptr->tail->value;
		if (l_ptr->size == 1)
		{
				free(l_ptr->head);
				l_ptr->head = l_ptr->tail = NULL;
		}
		else
		{
				tmp = l_ptr->tail->prev;
				tmp->next = NULL;
				free(l_ptr->tail);
				l_ptr->tail = tmp;
		}

		l_ptr->size--;
		return val;
}

value_t front(list_t *l_ptr)
{
		if (l_ptr->size == 0)
				return(VERR);
		return(l_ptr->head->value);
}

value_t back(list_t *l_ptr)
{
		if (l_ptr->size == 0)
				return(VERR);
		return(l_ptr->tail->value);
}

value_t insert(list_t *l_ptr, msize_t index, value_t val)
{
		if (index >= l_ptr->size)
				return(VERR);
		node_t *tmp, *new_nptr;
		tmp = node_at(l_ptr, index);
		if (tmp == l_ptr->head)
				push_front(l_ptr, val);
		else if (tmp == l_ptr->tail)
				push_back(l_ptr, val);
		else
		{      // not head, not tail, right shift
				new_nptr = init_node(val);
				new_nptr->prev = tmp->prev;
				tmp->prev->next = new_nptr;
				new_nptr->next = tmp;
				tmp->prev = new_nptr;
				l_ptr->size++;
		}
		return(val);
}

value_t erase(list_t *l_ptr, msize_t index)
{
		if (index >= l_ptr->size)
				return(VERR);
		node_t *tmp = node_at(l_ptr, index);
		if (tmp == l_ptr->head)
				return(pop_front(l_ptr));
		else if (tmp == l_ptr->tail)
				return(pop_back(l_ptr)); 
		value_t ret_val = tmp->value;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
		l_ptr->size--;
		return(ret_val);
}

value_t value_n_from_the_end(list_t *l_ptr, msize_t index)
{
		if (index >= l_ptr->size)
				return(VERR);
		msize_t i = l_ptr->size - 1, bound = l_ptr->size - index - 1;
		node_t *tmp = l_ptr->tail;
		for (; i > bound; i--)
				tmp = tmp->prev;
		return(tmp->value);
}

void reverse(list_t *l_ptr)
{
		node_t *curr, *tmp;
		if (l_ptr->size > 1)
		{
				curr = l_ptr->head;
				while (curr != NULL)
				{
						tmp = curr->next;
						curr->next = curr->prev;
						curr->prev = tmp;
						curr = tmp;
				}
				curr = l_ptr->head;
				l_ptr->head = l_ptr->tail;
				l_ptr->tail = curr;
		}
}

msize_t remove_value(list_t *l_ptr, value_t val)
{
		node_t *tmp = l_ptr->head;
		if (l_ptr->size == 0)
				return(SIZERR);
		if (l_ptr->head->value == val)
		{
				pop_front(l_ptr);
				return(0);
		}
		else if (l_ptr->tail->value = val)
		{
				pop_back(l_ptr);
				return(l_ptr->size - 1);
		}
		else
		{
				for (msize_t i = 1; i < l_ptr->size - 1; i++)
				{
						if (tmp->value == val)
						{
								tmp->prev->next = tmp->next;
								tmp->next->prev = tmp->prev;
								free(tmp);
								l_ptr->size--;
								return(i);
						}
				}
		}
		// no match, get here
		return(SIZERR);
}

void pr_list(list_t *l_ptr)
{
		node_t *tmp = l_ptr->head; int n = 0;
		printf("\t\tHEAD at: %p, Tail at: %p, size: %d front: %d, back: %d\n\t\t", l_ptr->head, l_ptr->tail, l_ptr->size, front(l_ptr), back(l_ptr));
		while (tmp != NULL)
		{
				printf(" %d: %d\t", n, tmp->value);
				n++;
				if (n != 0 && n % 10 == 0)
						printf("\n\t\t");
				tmp = tmp->next;
		}
		putchar('\n');
}
int main(void)
{
		list_t lst;
		lst.head = lst.tail = NULL;
		lst.size = 0;
		printf("\t\tinitialized:\n");
		pr_list(&lst);
		printf("\t\tpush 100 (50 front, 50 back) random value\n");
		for (int i = 0; i < 50; i++)
		{
				push_front(&lst, 49 - i);
				push_back(&lst,  50 + i);
		}
		pr_list(&lst);
		printf("\t\terase , pop_back, pop_front 33 times\n");
		for (int i = 0; i < 33; i++)
		{
				erase(&lst, 0);
				pop_back(&lst);
				pop_front(&lst);
		}
		pr_list(&lst);
		printf("\t\tinsert 0-99:\n");
		for (int i = 0; i < 100; i++)
				insert(&lst, 0, i);
		pr_list(&lst);
		printf("\n\t\tnow call reverse: \n");
		reverse(&lst);
		pr_list(&lst);
		printf("\t\tValue_n_from_end(3): %d, value_at(3): %d\n", value_n_from_the_end(&lst, 3), value_at(&lst, 3));
		return(0);
}
						
