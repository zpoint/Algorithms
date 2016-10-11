#include <stdio.h>
#include <stdlib.h>
typedef int tree_date;
typedef struct Ntree
{
	struct Ntree *parent = NULL;
	struct Ntree *left = NULL;
	struct Ntree *right = NULL;
	tree_date date;
}node_tree;

node_tree *init_node(tree_date value, node_tree *parent = NULL, node_tree *left = NULL, node_tree *right = NULL)
{
	node_tree *new_node = (node_tree *)malloc(sizeof(node_tree));
	new_node->date = value;
	new_node->left = left;
	new_node->parent = parent;
	new_node->right = right;
	return new_node;
}

int main(void)
{
	
}
