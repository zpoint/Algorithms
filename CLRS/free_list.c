#include <stdio.h>
#include <stdlib.h>

typedef struct NT
{
	struct NT *prev = NULL;
	int key;
	struct NT *next = NULL;
	int maxlength;
}node_t;

node_t *free_node = NULL;

node_t *allocate_object()
{
	if (free_node == NULL)
	{
		fprintf(stderr, "Out of spaces! function: allocate_object\n");
		exit(0);
	}
	else
	{
		node_t *x = free_node;
		free_node = x->next;
		return x;
	}
}

void free_object(node_t *x)
{
	x->next = free_node;
	free_node = x;
}

int mian(void)
{
	node_t f[10];
	return 0;
}