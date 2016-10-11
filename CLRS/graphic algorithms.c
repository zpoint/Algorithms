#include <stdio.h>
#include <stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
unsigned int global_time = 0;
typedef unsigned int color_t;
typedef struct adjacent_type graphic_t;
typedef struct vertex_type
{
	int x = INT_MIN;
	int y = INT_MIN;
	color_t color = WHITE;
	unsigned int distance = UINT_MAX;
	unsigned int finish_time = UINT_MAX;
	struct vertex_type *predecessor = NULL;
	struct adjacent_type *adjacent = NULL;
}vertex_t;
typedef struct adjacent_type
{
	vertex_t **arr;
	int length;
}adj_t;
//quene function && queue structure
typedef vertex_t q_content;
typedef struct qnode_type
{
	q_content *content = NULL;
	struct qnode_type *front;
	struct qnode_type *behind;
}qnode_t;
typedef struct quene_type
{
	qnode_type *head = NULL;
	qnode_type *tail = NULL;
	unsigned int length = 0;
}queue_t;
queue_t *make_queue(void)
{
	queue_t *new_queue = (queue_t *)malloc(sizeof(queue_t)), temp;
	new_queue->head = temp.head;
	new_queue->tail = temp.tail;
	new_queue->length = temp.length;
	return new_queue;
}
bool enqueue(queue_t *Q, q_content *content)
{
	qnode_t *new_qnode = (qnode_t *)malloc(sizeof(new_qnode)), *tail = NULL;
	new_qnode->content = content;
	if (Q->head == NULL)
	{
		new_qnode->behind = new_qnode->front = new_qnode;
		Q->head = new_qnode;
		Q->tail = new_qnode;
	}
	else
	{
		tail = Q->tail;
		tail->behind = new_qnode;
		new_qnode->front = tail;
		new_qnode->behind = NULL;
		Q->tail = new_qnode;
	}
	Q->length += 1;
	return true;
}
q_content *dequeue(queue_t *Q)
{
	qnode_t *tail = Q->tail;
	q_content *q = NULL;
	if (Q->head == NULL)
		return NULL;
	else if (Q->head == Q->tail)
		Q->head = Q->tail = NULL;
	else
	{
		Q->tail = tail->front;
		tail->front->behind = NULL;
	}
	
	Q->length -= 1;
	q = tail->content;
	free(tail);
	return q;
}
//quene done
//graphic begin
vertex_t *BFS(graphic_t *G, vertex_t *s)
{
	vertex_t *node = NULL, *adj_node = NULL;
	queue_t *Q = NULL;
	qnode_t *qnode = NULL;
	for (int i = 0; i < G->length; i++)
	{
		node = G->arr[i];
		node->color = WHITE;
		node->distance = UINT_MAX;
		node->predecessor = NULL;
	}
	s->color = GRAY;
	s->distance = 0;
	s->predecessor = NULL;
	Q = make_queue();
	enqueue(Q, s);
	while (Q->length != 0)
	{
		node = dequeue(Q);
		for (int i = 0; i < node->adjacent->length; i++)
		{
			adj_node = node->adjacent->arr[i];
			if (adj_node->color == WHITE)
			{
				adj_node->color = GRAY;
				adj_node->distance = node->distance + 1;
				adj_node->predecessor = node;
				enqueue(Q, adj_node);
			}
			node->color = BLACK;
		}
		node->color = BLACK;
	}
	free(Q); 
	return s;
}
void print_path(graphic_t *G, vertex_t *s, vertex_t *v)
{
	if (s == v)
		printf("addrss:%p\tdistance:%d\tx:%d\ty:%d\n", s, s->distance, s->x, s->y);
	else if (v->predecessor == NULL)
		printf("No path from vertex :(x,y)(%d, %d) to vertex:(x,y)(%d, %d)\n", s->x, s->y, v->x, v->y);
	else
	{
		print_path(G, s, v->predecessor);
		printf("addrss:%p\tdistance:%d\tx:%d\ty:%d\n", s, s->distance, s->x, s->y);
	}
}
void DFS_VISIT(vertex_t *node)
{
	vertex_t *adj_node = NULL;
	node->color = GRAY;
	global_time += 1;
	node->distance = global_time;
	for (int i = 0;i < node->adjacent->length;i++)
	{
		adj_node = node->adjacent->arr[i];
		if (adj_node->color == WHITE)
		{
			adj_node->predecessor = node;
			DFS_VISIT(adj_node);
		}
	}
	node->color = BLACK;
	node->finish_time = global_time + 1;
}
void DFS(graphic_t *G)
{
	vertex_t *node = NULL;
	for (int i = 0;i < G->length; i++)
	{
		node = G->arr[i];
		node->color = WHITE;
		node->predecessor = NULL;
	}
	global_time = 0;
	for (int i = 0; i < G->length; i++)
	{
		node = G->arr[i];
		if (node->color == WHITE)
			DFS_VISIT(node);
	}
}
int main(void)
{
	printf("%x\n", UINT_MAX);
}