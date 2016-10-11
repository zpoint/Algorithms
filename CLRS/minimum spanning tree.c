#include <stdio.h>
#include <stdlib.h>
#define KEY_MAX UINT_MAX
#define KEY_MIN 0
typedef int key_t;
typedef struct vertex_type
{
	int x;
	int y;
	key_t key = INT_MIN;
	struct vertex_type *predecessor = NULL;
	int degree = 0;
	int color = 0;
}vertex_t;
typedef struct edge_element
{
	set_t *set = NULL;
	unsigned int weight = 0;
};
typedef struct edges_type
{
	struct edge_element **start = NULL;
	int length = 0;
};
typedef struct graphic_type
{
	vertex_t **start = NULL;
	unsigned int length = 0;
	struct edges_type *edges = NULL;
};
//set
typedef vertex_t set_element_t;
typedef struct set_type
{
	set_element_t **start = NULL;
	unsigned int length = 0;
}set_t;
typedef struct set_list_t
{
	set_t **start = NULL;
	unsigned int length = 0;
};
/*make element
void make_element(set_element_t *element)
{
	set_element_t *new_element = (set_element_t *)malloc(sizeof(set_element_t));
	new_element->degree = element->degree;
	new_element->key = element->key;
	new_element->predecessor = element->predecessor;
	new_element->color = element->color;
	new_element->x = element->x;
	new_element->y = element->y;
	
}
*/
set_t *make_set(set_element_t *element)
{
	set_t *new_set = (set_t *)malloc(sizeof(set_t));
	set_element_t **arr = (set_element_t **)malloc(sizeof(set_element_t *));
	arr[0] = element;
	new_set->start = arr;
	new_set->length = 1;
	return new_set;
}
set_t *find_set(struct set_list_t *list,set_element_t *element)
{
	set_t *each_set = NULL;
	for (int i = 0;i < list->length; i++)
	{
		each_set = list->start[i];
		for (int j = 0;j < each_set->length; j++)
		{
			if (each_set->start[i] == element)
				return each_set;
		}
	}
	return NULL;
}
set_t *copy_setb2seta(set_t *seta, set_t *setb)
{
	int alength = seta->length, blength = setb->length;
	seta->start = (set_element_t **)realloc(seta->start, sizeof(set_element_t *) * (alength + blength));
	for (int i = 0; i < blength; i++)
	{
		seta->start[i + alength] = setb->start[i];
	}
	free(setb);
	return seta;
}
set_t *union_set(set_t *seta, set_t *setb)
{
	if (setb->length == 0)
	{
		free(setb);
		return seta;
	}
	else if (seta->length == 0)
	{
		free(seta);
		return setb;
	}
	else if (seta->length > setb->length)
		return copy_setb2seta(seta, setb);
	else
		return copy_setb2seta(setb, seta);
}
set_t *make_kruskal(graphic_type *G)
{
	set_t *A = (set_t *)malloc(sizeof(set_t));
	set_list_t *set_list = NULL;
	vertex_t **vertex_list = G->start;
	edge_element **edge_list = G->edges->start;
	edge_element *each_edge = NULL;
	//make_set && append each_set to set_list
	//sort edges;
	for (int i = 0;i < G->edges->length; i++)
	{
		each_edge = G->edges->start[i];
		if (find_set(set_list, each_edge->set->start[0]) != find_set(set_list, each_edge->set->start[1]))
		{
			A = union_set(A, each_edge->set);
			//modify set_list, remove each_edge->set->start[1], set SET(each_edge->set->start[0]) = SET(each_edge->set->start[0], each_edge->set->start[0]);
		}
	}
	return A;
}
int mian(void)
{
	return 0;
}