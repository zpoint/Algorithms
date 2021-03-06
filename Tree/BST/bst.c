#include <stdio.h>
#include <stdlib.h>
typedef int val_t;
typedef int msize_t;

typedef struct Node_t
{
		struct Node_t *left;
		struct Node_t *right;
		val_t value;
}node_t;

typedef struct Search_t
{
		struct Node_t *curr;
		struct Node_t *parent;
}search_t;

typedef struct QNode_t
{
		struct Node_t *value;
		struct QNode_t *next;
		struct QNode_t *prev;
}qnode_t;

typedef struct Queue_t
{
		struct QNode_t *head;
		struct QNode_t *tail;
		msize_t length;
}queue_t;

queue_t *queue_global;
int helper2_2(node_t *);

int max(int a, int b)
{
		return(a > b ? a:b);
}

int min(int a, int b)
{
		return(a < b ? a:b);
}

queue_t *init_queue(void)
{
		queue_t *q = malloc(sizeof(queue_t));
		q->head = NULL;
		q->tail = NULL;
		q->length = 0;
		return(q);
}


void *enqueue(queue_t *queue, node_t *node)
{
		qnode_t *new_qnode = malloc(sizeof(qnode_t));
		new_qnode->value = node;
		new_qnode->prev = NULL;
		new_qnode->next = NULL;
		if (queue->length == 0)
		{
				queue->head = queue->tail = new_qnode;
				queue->length++;
		}
		else
		{
				queue->tail->next = new_qnode;
				new_qnode->prev = queue->tail;
				queue->tail = new_qnode;
				queue->length++;
		}
}

node_t *dequeue(queue_t *queue)
{
		//printf("dequeue: %d\n", queue->head->value->value);
		if (queue->length <= 0)
				return(NULL);
		qnode_t *first_q = queue->head;
		node_t *ret_node = first_q->value;
		if (queue->length == 1)
				queue->head = queue->tail = NULL;
		else
		{
				queue->head = first_q->next;
				queue->head->prev = NULL;
		}
		queue->length--;
		free(first_q);
		return(ret_node);
}

		

node_t *getleft(node_t *node)
{
		return(node->left);
}

node_t *getright(node_t *node)
{
		return(node->right);
}

val_t getvalue(node_t *node)
{
		return(node->value);
}

node_t *create_node(val_t value)
{
		node_t *new_node = malloc(sizeof(node_t));
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->value = value;
		return(new_node);
}

int insert(node_t *tree, val_t value)
{
		node_t *new_node = create_node(value);
		node_t *parent;
		val_t curr_val;
		while (tree != NULL)
		{
				if ((curr_val = getvalue(tree)) == value)
						return(-1);
				else if (value < curr_val)
					{ parent = tree; tree = getleft(tree); }
				else
					{ parent = tree; tree = getright(tree);}
		}
		if (value < curr_val)
				parent->left = new_node;
		else
				parent->right = new_node;
		return(1);
}

struct Search_t search(node_t *tree, val_t value)
{
		val_t curr_val;
		node_t *parent = NULL;
		struct Search_t result;
		while (tree != NULL)
		{
				curr_val = getvalue(tree);
				if (value == curr_val)
						{ result.parent = parent; result.curr = tree; return(result);}
				else if (value < curr_val)
						{ parent = tree; tree = getleft(tree);}
				else
						{ parent = tree; tree = getright(tree);}
		}
		result.parent = NULL;
		result.curr = NULL;
		return(result);
}


struct Search_t successor(node_t *tree)
{
		node_t *parent = tree;
		tree = getright(tree);
		node_t *succ = tree;
		struct Search_t result;
		while (tree != NULL)
		{
				succ = tree; 
				tree = getleft(tree); 
				if (tree != NULL && getleft(tree) != NULL)
						parent = succ;
			
		}
		result.parent = parent;
		result.curr = succ;
		return(result);
}


val_t delete(node_t *tree, val_t value)
{
		node_t *delnode, *left, *right, *parent, *succ, *succ_parent;
		struct Search_t result = search(tree, value);
		val_t del_val;
		if ((delnode = result.curr) == NULL)
				return(-1);
		parent = result.parent;
		del_val = getvalue(delnode);
		left = getleft(delnode);
		right = getright(delnode);
		if (left == NULL && right == NULL)
		{
				if (getleft(parent) == delnode)
						parent->left = NULL;
				else
						parent->right = NULL;
				free(delnode);
		}
		else if (!(left != NULL && right != NULL)) // one child
		{

				if (left != NULL)
						parent->left = left;
				else
						parent->right = right;
				free(delnode);
		}
		else // two child
		{
				result = successor(delnode);
				succ_parent = result.parent;
				succ = result.curr;
				delnode->value = getvalue(succ);
				if (getright(succ) != NULL)
				{
						succ_parent->right = getright(succ);
				}
				free(succ);
		}
		return(del_val);
}


void preorder_traversal(node_t *tree)
{
		if (tree != NULL)
		{
				printf("%d\t", getvalue(tree));
				preorder_traversal(getleft(tree));
				preorder_traversal(getright(tree));
		}
}

void postorder_traversal(node_t *tree)
{
		if (tree != NULL)
		{
				postorder_traversal(getleft(tree));
				postorder_traversal(getright(tree));
				printf("%d\t", getvalue(tree));
		}
}

void inorder_traversal(node_t *tree)
{
		if (tree != NULL)
		{
				inorder_traversal(getleft(tree));
				printf("%d\t", getvalue(tree));
				inorder_traversal(getright(tree));
		}
}

void levelorder_helper(void)
{
		node_t *tree;
		while ((tree = dequeue(queue_global)) != NULL)
		{
				printf("%d\t", getvalue(tree));
				if (getleft(tree) != NULL)
						enqueue(queue_global, getleft(tree));
				if (getright(tree) != NULL)
						enqueue(queue_global, getright(tree));
		}
}

void levelorder_traversal(node_t *tree)
{
		if (tree != NULL)
		{
				enqueue(queue_global, tree);
				levelorder_helper();
		}
}

int find_height(node_t *tree)
{
		// return the count of edges to the leaf
		if (tree == NULL)
				return(-1);
		return(max(find_height(tree->left), find_height(tree->right)) + 1);
}

int find_node(node_t *tree)
{
		return(find_height(tree) - 1);
}

int depth_helper(node_t *node, val_t value, int depth)
{
		if (node == NULL)
				return(-1);
		if (getvalue(node) == value)
				return(depth);
		return(max(depth_helper(getleft(node), value, depth+1), depth_helper(getright(node), value, depth+1)));
}


int find_depth(node_t *tree, val_t value)
{
		return(depth_helper(tree, value, 0));
}

int isbinaryhelper(node_t *node, val_t min_val, val_t max_val)
{
		if (node == NULL)
				return(1);
		if (getvalue(node) > min_val && getvalue(node) < max_val)
				return(min(isbinaryhelper(getleft(node), min_val, getvalue(node)), isbinaryhelper(getright(node), getvalue(node), max_val)));
		return(-1);
}

int isbinaryhelper2_inorderhelper(node_t *node)
{
		// must be called from isbinarthelper2, or error will occur
		static val_t prev = 1 << 31;
		if (getvalue(node) <= prev)
				return(-1);
		prev = getvalue(node);
		return(1);
}

int isbinarytree2(node_t *node)
{
		if (node != NULL)
		{
				if (isbinarytree2(getleft(node)) > 0)
						if (isbinaryhelper2_inorderhelper(node) > 0)
							if (isbinarytree2(getright(node)) > 0)
									return(1);
				return(-1);
		}
		return(1);
}




int isbinarytree(node_t *tree)
{
		return(isbinaryhelper(tree, 1<<31, 1<<31 ^ -1));
}

void delete_tree(node_t *tree)
{
		if (tree != NULL)
		{
				delete_tree(getleft(tree));
				delete_tree(getright(tree));
				free(tree);
		}
}



int main(int argc, char *argv[])
{
		/* 
		   5
		 /  \
		3   10
	   /     \
	   2     15
	  /
     1
	 */
		queue_global = init_queue();
		node_t *tree = create_node(5);
		insert(tree, 10);
		insert(tree, 15);
		insert(tree, 3);
		insert(tree, 2);
		insert(tree, 1);
		delete(tree, 1);
		delete(tree, 15);
		insert(tree, 1);
		insert(tree, 15);
		printf("preorder_traversal:");
		preorder_traversal(tree);
		printf("\npostorder_traversal:");
		postorder_traversal(tree);
		printf("\ninorder_traversal:");
		inorder_traversal(tree);
		printf("\nlevelorder_traversal:");
		levelorder_traversal(tree);
		printf("\n");
		printf("Height: %d, node: %d depth of 15: %d isbinarytree(tree): %d, %d\n", find_height(tree), find_node(tree), find_depth(tree, 15), isbinarytree(tree), isbinarytree2(tree));
		return(0);
}
