#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0


typedef int val_t;
typedef struct Node_t
{
		struct Node_t *left;
		struct Node_t *right;
		struct Node_t *parent;
		int color;
		val_t value;
}node_t;

typedef struct
{
		node_t *root;
}tree_t;	

node_t *NIL = NULL; // sentinel

tree_t *init_tree(void)
{
		tree_t *new_tree = malloc(sizeof(tree_t));
		new_tree->root = NIL;
		return(new_tree);
}

node_t *init_node(val_t value)
{
		node_t *new_node = malloc(sizeof(node_t));
		new_node->left = NIL;
		new_node->right = NIL;
		new_node->parent = NIL;
		new_node->value = value;
		new_node->color = RED;
		return(new_node);
}

int left_rotate(tree_t *tree, node_t *up, node_t *down)
{
		if (down != up->right || down == NIL)
		{ fprintf(stderr, "Error in left_rotate"); return(-1);}
		node_t *middle = down->left;
		if (tree->root == up)
				tree->root = down;
		else if (up == up->parent->left)
				up->parent->left = down;
		else 
				up->parent->right = down;
		down->parent = up->parent;

		if (middle != NULL)
				middle->parent = up;
		up->right = middle;

		up->parent = down;
		down->left = up;
		return(1);
}

int right_rotate(tree_t *tree, node_t *up, node_t *down)
{
		if (down != up->left || down == NIL)
		{ fprintf(stderr, "Error in right_rotate"); return(-1); }
		node_t *middle = down->right;
		if (up == tree->root)
				tree->root = down;
		else if (up == up->parent->left)
				up->parent->left = down;
		else
				up->parent->right = down;
		down->parent = up->parent;

		if (middle != NULL)
				middle->parent = up;
		up->left = middle;

		up->parent = down;
		down->right = up;
		return(1);
}


int check(tree_t *tree, node_t *node)
{
		/*
		// node must not be root, node's color must be BLACK
		if (node->parent == tree->root || node->parent == BLACK)
				return(1); // when recheck, may happen, means done
		*/
		// node is RED, node is new insert's parent
		if (node->color == BLACK)
				return(1); // no need to check
		node_t *sibling;
		if (node == node->parent->left)
				sibling = node->parent->right;
		else
				sibling = node->parent->left;
		if (sibling != NIL && sibling->color == RED) // sibling color RED
		{
				node->color = BLACK;
				sibling->color = BLACK;
				if (node->parent == tree->root)
						return(1);
				else
				{
						node->parent->color = RED;
						check(tree, node->parent->parent);
				}
		}
		else // sibling NIL or BLACK, but node is red
		{
				if (node == node->parent->left && node->left->color == RED) // LL
				{
						node->color = BLACK;
						node->parent->color = RED;
						right_rotate(tree, node->parent, node);
				}
				else if (node == node->parent->left && node->right->color == RED) // LR
				{
						left_rotate(tree, node, node->right); // after rotate, node become the down node, node->parent is the "node->right" after rotate
						node = node->parent; // reset node
						node->color = BLACK;
						node->parent->color = RED;
						right_rotate(tree, node->parent, node);
				}
				else if (node == node->parent->right && node->left->color == RED) // RL
				{
						right_rotate(tree, node, node->left);
						node = node->parent;
						node->color = BLACK;
						node->parent->color = RED;
						left_rotate(tree, node->parent, node);
				}
				else // RR
				{
						node->color = BLACK;
						node->parent->color = RED;
						left_rotate(tree, node->parent, node);
				}
				return(1);
		}
}

int insert(tree_t *tree, val_t value)
{
		node_t *curr = tree->root, *parent;
		while (curr != NIL)
		{
				if (value == curr->value)
						return(-1);
				else if (value < curr->value)
				{ parent = curr; curr = curr->left; }
				else
				{ parent = curr; curr = curr->right; }
		}
		node_t *new_node = init_node(value);
		if (curr == tree->root)
		{ tree->root = new_node; new_node->color = BLACK; }
		else if (value < parent->value)
		{
				parent->left = new_node;
				check(tree, parent);
		}
		else // value > parent.value
		{
				parent->right = new_node;
				check(tree, parent);
		}
		return(1);
}

int main(int argc, char *argv[])
{
		printf("NIL: %p\n", NIL);
		return(0);
}
