#include <stdio.h>
#include <stdlib.h>
/* below for balance command */
#define LL 0
#define LR 1
#define RL 2
#define RR 3
/* Done */
typedef int val_t;
typedef struct Node_t
{
		struct Node_t *left;
		struct Node_t *right;
		struct Node_t *parent;
		val_t value;
		int left_height;
		int right_height;
}node_t;

typedef struct Tree_t
{
		node_t *root;
}tree_t;

int height(node_t *node)
{
		if (node == NULL)
				return(-1);
		else if (node->left_height > node->right_height)
				return(node->left_height + 1);
		else
				return(node->right_height + 1);
}

int max(int a, int b)
{
		if (a > b)
				return(a);
		return(b);
}

node_t *search_node(tree_t *tree, val_t value)
{
		node_t *curr = tree->root;
		while (curr != NULL)
		{
				if (curr->value == value)
						return(curr);
				else if (value < curr->value)
						curr = curr->left;
				else
						curr = curr->right;
		}
		return(curr);
}

int left_rotate(tree_t *tree, node_t *up, node_t *down)
{
		if (down == up->right && down != NULL)
		{
				node_t *p_up = up->parent, *l_down = down->left;
				if (p_up == NULL) // up is root
						tree->root = down;
				else if (up == p_up->right)
						p_up->right = down;
				else
						p_up->left = down;
				down->parent = p_up;

				if (l_down != NULL)
				{
						l_down->parent = up;
						up->right = l_down;
				}
				else
						up->right = l_down;
				down->left = up;
				up->parent = down;
				up->left_height = height(up->left);
				up->right_height = height(up->right);
				down->left_height = height(down->left);
				down->right_height = height(down->right);
				return(1);
		}
		return(0);
}

int right_rotate(tree_t *tree, node_t *up, node_t *down)
{
		if (down == up->left && down != NULL)
		{
				node_t *p_up = up->parent, *r_down = down->right;
				if (up == NULL)
						tree->root = down;
				else if (up == p_up->left)
						p_up->left = down;
				else
						p_up->right = down;
				down->parent = p_up;

				if (r_down != NULL)
				{
						r_down->parent = up;
						up->left = r_down;
				}
				else
						up->left = r_down;
				down->right = up;
				up->parent = down;
				up->left_height = height(up->left);
				up->right_height = height(up->right);
				down->left_height = height(down->left);
				down->right_height = height(down->right);
				return(1);
		}
		return(0);
}

node_t *fix_helper(tree_t *tree, node_t *up, int cmd)
{
		switch (cmd)
		{
				case LL: right_rotate(tree, up, up->left);
						 break;
				case LR: left_rotate(tree, up->left, up->left->right);
						 right_rotate(tree, up, up->left);
						 break;
				case RR: left_rotate(tree, up, up->right);
						 break;
				case RL: right_rotate(tree, up->right, up->right->left);
						 left_rotate(tree, up, up->right);
						 break;
				default: return(NULL);
		}
		return(up->parent);
}

node_t *fix_balance(tree_t *tree, node_t *upmost)
{
		if (upmost->left_height - upmost->right_height > 1) // LL or LR
		{
				if (upmost->left->left != NULL)
						return(fix_helper(tree, upmost, LL));
				else
						return(fix_helper(tree, upmost, LR));
		}
		else if (upmost->right_height - upmost->left_height > 1) // RL or RR
		{
				if (upmost->right->right != NULL)
						return(fix_helper(tree, upmost, RR));
				else
						return(fix_helper(tree, upmost, RL));
		}
		else
		{
				return(NULL);
		}
}

int insert_fix(tree_t *tree, node_t *node)
{
		node_t *tmp;
		while (node != NULL)
		{
				node->left_height = height(node->left);
				node->right_height = height(node->right);
				if ((tmp = fix_balance(tree, node)) == NULL)
						node = node->parent;
				else
						node = tmp;
		}
		return(1);
}


int insert(tree_t *tree, val_t value)
{
		node_t *curr = tree->root, *parent, *tmp;
		while (curr != NULL)
		{
				if (value == curr->value)
						return(-1); // can't insert same value
				else if (value < curr->value)
				{
						parent = curr;
						curr = curr->left;
				}
				else
				{
						parent = curr;
						curr = curr->right;
				}
		}
		tmp = malloc(sizeof(node_t));
		tmp->value = value;
		tmp->left_height = -1;
		tmp->right_height = -1;
		tmp->left = NULL;
		tmp->right = NULL;
		if (tree->root == NULL)
		{
				tmp->parent = NULL;
				tree->root = tmp;
		}
		else if (value < parent->value)
		{
				tmp->parent = parent;
				parent->left = tmp;
				insert_fix(tree, tmp);
		}
		else
		{
				tmp->parent = parent;
				parent->right = tmp;
				insert_fix(tree, tmp);
		}
		return(1);
}

node_t *succcessor(node_t *node)
{
		if ((node = node->right) == NULL)
				return(node);
		else
		{
				while (node->left != NULL)
						node = node->left;
				return(node);
		}
}


int delete(tree_t *tree, val_t value)
{
		node_t *curr;
		if ((curr = search_node(tree, value)) == NULL)
				return(-1);
		if (curr == tree->root)
		{
				free(curr);
				tree->root = NULL;
		}
		else if (curr->left == NULL && curr->right == NULL)
		{
				if (curr == curr->parent->left)
						curr->parent->left = NULL;
				else
						curr->parent->right = NULL;
		}
		else if (!(curr->left != NULL && curr->right != NULL)) // one child
		{
				if (curr == curr->parent->left)
				{
						if (curr->left != NULL)
						{
								curr->parent->left = curr->left;
								curr->left->parent = curr->parent;
						}
						else
						{
								curr->parent->left = curr->right;
								curr->right->parent = curr->parent;
						}
				}
				else
				{
						if (curr->left != NULL)
						{
								curr->parent->right = curr->left;
								curr->left->parent = curr->parent;
						}
						else
						{
								curr->parent->right = curr->right;
								curr->right->parent = curr->parent;
						}
				}
		}
		else // two child
		{
				node_t *succ = succcessor(curr);
				curr->value = succ->value; // replace current value with successor's value, and delete succ node
				if (succ->right != NULL) // successor mustn't have left node
				{
						succ->parent->right = succ->right;
						succ->right->parent = succ->parent;
				}
				else
						succ->parent->right = NULL;
				curr = succ; // for later free(node), and fix_balance
		}
		insert_fix(tree, curr->parent);
		free(curr);
		return(1);
}


void inorder_helper(node_t *node)
{
		if (node != NULL)
		{
				inorder_helper(node->left);
				printf("node value: %d, left_height: %d, right_height: %d, node_height: %d\n", node->value, node->left_height, node->right_height,height(node));
				inorder_helper(node->right);
		}
}

void inorder_traversal(tree_t *tree)
{
		inorder_helper(tree->root);
}

int main(int argc, char *argv[])
{
		tree_t tree;
		tree.root = NULL;
		insert(&tree, 5);
		insert(&tree, 10);
		insert(&tree, 8);
		insert(&tree, 13);
		insert(&tree, 9);
		delete(&tree, 10);
		inorder_traversal(&tree);
		return(0);
}
