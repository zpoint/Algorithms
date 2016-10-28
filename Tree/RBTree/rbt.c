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
	tree_t *new_tree = (tree_t *)malloc(sizeof(tree_t));
	new_tree->root = NIL;
	return(new_tree);
}

node_t *init_node(val_t value)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
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
	{
		fprintf(stderr, "Error in left_rotate"); return(-1);
	}
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
	{
		fprintf(stderr, "Error in right_rotate"); return(-1);
	}
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
	node_t *sibling = NIL;
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
			return(check(tree, node->parent->parent));
		}
	}
	else // sibling NIL or BLACK, but node is red
	{
		if (node == node->parent->left && (node->left != NIL && node->left->color == RED)) // LL
		{
			node->color = BLACK;
			node->parent->color = RED;
			right_rotate(tree, node->parent, node);
		}
		else if (node == node->parent->left && (node->right != NIL && node->right->color == RED)) // LR
		{
			left_rotate(tree, node, node->right); // after rotate, node become the down node, node->parent is the "node->right" after rotate
			node = node->parent; // reset node
			node->color = BLACK;
			node->parent->color = RED;
			right_rotate(tree, node->parent, node);
		}
		else if (node == node->parent->right && (node->left != NIL && node->left->color == RED)) // RL
		{
			right_rotate(tree, node, node->left);
			node = node->parent;
			node->color = BLACK;
			node->parent->color = RED;
			left_rotate(tree, node->parent, node);
		}
		else if (node == node->parent->right && (node->right != NIL && node->right->color == RED)) // RR
		{
			node->color = BLACK;
			node->parent->color = RED;
			left_rotate(tree, node->parent, node);
		}
		else
			fprintf(stderr, "Error!!!!!!!!!\tnode: %d\n", node->value);
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
		{
			parent = curr; curr = curr->left;
		}
		else
		{
			parent = curr; curr = curr->right;
		}
	}
	node_t *new_node = init_node(value);
	if (curr == tree->root)
	{
		tree->root = new_node; new_node->color = BLACK;
	}
	else if (value < parent->value)
	{
		new_node->parent = parent;
		parent->left = new_node;
		check(tree, parent);
	}
	else // value > parent.value
	{
		new_node->parent = parent;
		parent->right = new_node;
		check(tree, parent);
	}
	return(1);
}

node_t *successor(node_t *node)
{
	node_t *curr = node->right;
	while (curr->left != NIL)
		curr = curr->left;
	return(curr);
}

int getcolor(node_t *node)
{
	if (node == NIL || node->color == BLACK)
		return(BLACK);
	return(RED);
}

int delete_helper(tree_t *tree, node_t *node)
{
	// Caller must make sure node is a node of tree
	Node_t *succ;
	if (node->left != NIL && node->right != NIL)
	{
		succ = successor(node);
		node->value = succ->value;
		return(delete_helper(tree, succ)); // successor have the old value
	}
	// Below node must have 1 or 0 child with not null value
	else if (node->color == RED) // if color of node is RED, just delete it
	{
		if (node == node->parent->left)
		{
			if (node->left != NIL)
			{
				node->left->parent = node->parent;
				node->parent->left = node->left;
			}
			else if (node->right != NIL)
			{
				node->right->parent = node->parent;
				node->parent->left = node->right;
			}
			else
				node->parent->left = NIL;
		}
		else
		{
			if (node->left != NIL)
			{
				node->left->parent = node->parent;
				node->parent->right = node->left;
			}
			else if (node->right != NIL)
			{
				node->right->parent = node->parent;
				node->parent->right = node->right;
			}
			else
				node->parent->right = NIL;
		}
		free(node);
		return(1);
	}
	else
	{
		// below, node->COLOR is BLACK
		if (node->left != NIL && node->left->color == RED) // node->left->color is RED
		{
			node->left->color = BLACK;
			node->color = RED;
			return(delete_helper(tree, node));
		}
		else if (node->right != NIL && node->right->color == RED) // node->right->color is RED
		{
			node->right->color = BLACK;
			node->color = RED;
			return(delete_helper(tree, node));
		}
		else // double black situation:
		{
			if (node == tree->root) // case 1
			{
				if (node->left != NIL)
				{
					tree->root = node->left;
					node->left->parent = NIL;
				}
				else if (node->right != NIL)
				{
					tree->root = node->right;
					node->right->parent = NIL;
				}
				else
					tree->root = NIL;
				free(node);
				return(1);
			}

			node_t *sibling;
			if (node == node->parent->left)
				sibling = node->parent->right;
			else
				sibling = node->parent->left;
			// use getcolor() functon to get color of node
			if ()
		}
	}

}

int delete_node(tree_t *tree, val_t value)
{
	node_t *curr = tree->root;
	while (curr != NIL)
	{
		if (value == curr->value)
			break;
		else if (value < curr->value)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr == NIL)
		return(-1);
	return(delete_helper(tree, curr));
}

void middle_helper(node_t *node)
{
	if (node != NIL)
	{
		printf("value: %d\t color: %s\t", node->value, node->color == RED ? "RED" : "BLACK");
		if (node->parent == NIL)
			printf("parent: NIL\t");
		else
			printf("parent: %d\t", node->parent->value);
		if (node->left == NIL)
			printf("left: NIL\t");
		else
			printf("left: %d\t", node->left->value);
		if (node->right == NIL)
			printf("right: NIL\n");
		else
			printf("right: %d\n", node->right->value);
		middle_helper(node->left);
		middle_helper(node->right);
	}
}

void middle_order_traversal(tree_t *tree)
{
	printf("middle order traversal(first line is root):\n");
	middle_helper(tree->root);
}

int main(int argc, char *argv[])
{
	tree_t *tree = init_tree();
	insert(tree, 10);
	insert(tree, -10);
	insert(tree, 17);
	insert(tree, 15);
	insert(tree, 20);
	insert(tree, 40);
	insert(tree, 50);
	node_t *sibling = NIL;
	node_t *node = tree->root->right;
	middle_order_traversal(tree);
	return(0);
}