#include <stdio.h>
#include <stdlib.h>
typedef int tree_date;
struct tNode
{
	tree_date date;
	struct tNode *left_ptr = NULL;
	struct tNode *right_ptr = NULL;
}tree;

struct sNode
{
	struct tNode *tree_ptr = NULL;
	struct sNode *next_ptr = NULL;
};

void push(sNode **stack_ptr, tNode *tree_ptr)
{
	if ((*stack_ptr)->tree_ptr == NULL)
		(*stack_ptr)->tree_ptr = tree_ptr;
	else
	{
		sNode *new_stack_ptr = (sNode *)malloc(sizeof(sNode));
		new_stack_ptr->next_ptr = *stack_ptr;
		new_stack_ptr->tree_ptr = tree_ptr;
		*stack_ptr = new_stack_ptr;
	}
	//printf("Atfer push , (*stack_ptr)->tree_ptr->date:%d\n", (*stack_ptr)->tree_ptr->date);
}

tNode *pop(sNode **stack_pptr)
{
	if (*stack_pptr == NULL)
	{
		fprintf(stderr, "Empty stack, unable to pop function:pop\n");
		exit(0);
	}
	else
	{
		tNode *return_tree = (*stack_pptr)->tree_ptr;
		sNode *prev_stack_ptr = (*stack_pptr);
		*stack_pptr = (*stack_pptr)->next_ptr;
		free(prev_stack_ptr);
		return return_tree;
	}
}

int main(void)
{
/* Constructed binary tree is
	  1
	/   \
   2     3
  / \
 4   5
*/
	struct tNode t2;
	t2.date = 2;
	struct tNode t3;
	t3.date = 3;
	struct tNode t4;
	t4.date = 4;
	struct tNode t5;
	t5.date = 5;

	tree.date = 1;
	tree.left_ptr = &t2;
	tree.right_ptr = &t3;
	t2.left_ptr = &t4;
	t2.right_ptr = &t5;

	struct tNode *current_tree_ptr = &tree;
	struct tNode *poped_tree_ptr = NULL;
	struct sNode *stack_ptr = (sNode *) malloc(sizeof(sNode)); // call free inside function
	stack_ptr->next_ptr = NULL;
	struct sNode **stack_pptr = &stack_ptr;
	//printf("%p\n", stack_pptr);
	
	while (true)
	{
		while (current_tree_ptr != NULL)
		{
			//printf("current_tree_ptr->left_ptr:%p\n", current_tree_ptr->left_ptr);
			push(stack_pptr, current_tree_ptr);
			//printf("Main: *stack_pptr->tree->date: %d\n", (*stack_pptr)->tree_ptr->date);
			if (current_tree_ptr->left_ptr == NULL)
				current_tree_ptr = NULL;
			else
				current_tree_ptr = current_tree_ptr->left_ptr;
		}

		if ((*stack_pptr)->next_ptr != NULL)
		{
			//printf("(*stack_pptr)->tree_ptr: %p (*stack_pptr)->tree_ptr->date: %d\t", (*stack_pptr)->tree_ptr, (*stack_pptr)->tree_ptr->date);
			poped_tree_ptr = pop(stack_pptr);
			printf("%d  \t", poped_tree_ptr->date);
			current_tree_ptr = poped_tree_ptr->right_ptr;
			
		}

		else
			break;
				
	}
	printf("\n");
	return 0;
}