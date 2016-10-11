#include <stdio.h>
#include <stdlib.h>
typedef struct node_t
{
	int key;
	struct node_t *next;
}node_t;

void insert(node_t *node_init, int key)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->key = key;
	new_node->next = node_init->next;
	node_init->next = new_node;
}

node_t * search(node_t *init, int key)
{
	node_t *current_search_ptr = init;
	do
	{
		current_search_ptr = current_search_ptr->next;
	} while (current_search_ptr != init && current_search_ptr->key != key);
	return current_search_ptr;
}

void delete_node(node_t *node_init, int key)
{
	node_t *prev_target_node_ptr = node_init;
	node_t *being_deleted_node_ptr;
	while (prev_target_node_ptr->next->key != key && prev_target_node_ptr->next != node_init)
	{
		prev_target_node_ptr = prev_target_node_ptr->next;
	}
	if (prev_target_node_ptr->key != key)
	{
		fprintf(stderr, "No key:%d match in node, function delete_node", key);
		exit(0);
	}
	being_deleted_node_ptr = prev_target_node_ptr->next;
	prev_target_node_ptr->next = being_deleted_node_ptr->next;
	free(being_deleted_node_ptr);
}

node_t *init_node()
{
	node_t *node_init_ptr = (node_t *)malloc(sizeof(node_t));
	node_init_ptr->next = node_init_ptr;
	node_init_ptr->key = 0;
	return node_init_ptr;
}

void destory_node(node_t *node_init)
{
	node_t *node_next = node_init->next;
	node_t *being_freed_node;
	while (node_next != node_init)
	{
		being_freed_node = node_next;
		node_next = node_next->next;
		free(being_freed_node);
	}
}

int main(void)
{
	return 1;
}