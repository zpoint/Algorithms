#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLACK 1
typedef struct node_rb_tree
{
	unsigned char color;
	int key;
	struct node_rb_tree * parent;
	struct node_rb_tree * left;
	struct node_rb_tree * right;
}node;

typedef struct rbtree
{
	node * root;
	node * nil;
}Tree;

//function
void left_rotate(Tree *T, node *x)
{
	node *y = x->right;
	x->right = y->left;
	y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == T->nil)
		T->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}
void right_rotate(Tree *T, node *y)
{
	node *x = y->left;
	y->left = x->right;
	x->right->parent = y;
	x->parent = y->parent;
	if (y->parent == T->nil)
		T->root = y;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	x->right = y;
	y->parent = x;
}

void rb_insert(Tree *T, node *z)
{
	node *y = T->nil;
	node *x = T->root;
	while (x != T->nil)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == T->nil)
		T->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = T->nil;
	z->right = T->nil;
	z->color = RED;
	rb_insert_fixup(T, z);
}

node *rb_delete(Tree *T, node *z)
{
	node *y, *x = NULL;
	if (z->left == T->nil || z->right == T->nil)
		y = z;
	else
		y = tree_successor(T, z);

	if (y->left != T->nil)
		x = y->left;
	else
		x = y->right;
	x->parent = y->parent;
	if (y->parent == T->nil)
		T->root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	if (y != z)
		z->key = y->key;
	if (y->color == BLACK)
		rb_delete_fixup(T, x);
	return y;
}

void rb_delete_fixup(Tree *T, node *x)
{
	node *w = NULL;
	while (x != T->root && x->color == BLACK)
	{
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				left_rotate(T, x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(T, w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = RED;
				left_rotate(T, x->parent);
				x = T->root;
			}
		}
		else
		{
			w = x->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				right_rotate(T, x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = RED;
					w->color = RED;
					left_rotate(T, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				right_rotate(T, x->parent);
				x = T->root;
			}
		}
	}
	x->color = BLACK;
}
node *tree_successor(Tree *T, node *x)
{
	if (x->right != T->nil)
		return tree_minimum(T, x->right);
	node *y = x->parent;
	while (y != T->nil && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

node *tree_minimum(Tree *T, node *x)
{
	while (x->left != T->nil)
		x = x->left;
	return x;
}
void rb_insert_fixup(Tree *T, node *z)
{
	while (z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			node *uncle = z->parent->parent->right;
			if (uncle->color == RED)
			{
				z->parent->color = BLACK;
				uncle->color = BLACK;
				z->parent->parent = RED;
				z = z->parent->parent;
			}
			else 
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					left_rotate(T, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(T, z->parent->parent);
			}
		}
		else
		{
			node *uncle = z->parent->parent->left;
			if (uncle->color == RED)
			{
				z->parent->color = BLACK;
				uncle->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					right_rotate(T, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(T, z->parent->parent);
			}
		}
	}
	T->root->color = BLACK;
}
int main(void)
{
	node nil = { BLACK, NULL, NULL, NULL, NULL };
	node t1 = {BLACK, 1, NULL, &nil, &nil};
	node t4 = { RED, 4, NULL, &nil, &nil };
	node t5 = { BLACK, 5, NULL, &t4, &nil };
	node t2 = { RED, 2, NULL, &t1, &t5 };
	node t7 = { BLACK, 7, &nil, &t2, &nil };
	node t15 = { RED, 15, NULL, &nil, &nil };
	node t14 = { BLACK, 14, NULL, &nil, &t15 };
	node t8 = { BLACK, 8, NULL, &nil, &nil };
	node t11 = { RED, 11, &t7, &t8, &t14 };
	t8.parent = t14.parent = &t11;
	t15.parent = &t14;
	t7.right = &t11;
	t2.parent = &t7;
	t5.parent = &t2;
	t4.parent = &t5;
	t1.parent = &t2;
	return 0;
}
