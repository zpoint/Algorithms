#include <stdio.h>
#include <stdlib.h>
typedef struct b_tree_node_type
{
	int n = 0;
	int leaf = false;
	int *key = NULL;
	b_tree_node_type **child = NULL;
}bnode_t;

typedef struct btree_type
{
	bnode_t *root = NULL;
	int degree = 0;
}tree_t;

typedef struct search_result_type
{
	bnode_t *node;
	int key_index;
}btree_result_t;

bnode_t *disk_read(bnode_t *node)
{
	return node;
}
bnode_t *disk_write(bnode_t *node)
{
	return node;
}
bnode_t *create_node(void)
{
	bnode_t node;
	bnode_t *new_node = (bnode_t *)malloc(sizeof(bnode_t));
	new_node->child = node.child;
	new_node->key = node.key;
	new_node->leaf = node.leaf;
	new_node->n = node.n;
	return new_node;
}
bnode_t *btree_merge(bnode_t *left, bnode_t *right, int key)
{
	int left_n = left->n;
	left->key[left_n] = key;
	for (int i = 0; i < right->n; i++)
	{
		left->key[i + left_n + 1] = right->key[i];
		left->child[i + left_n + 1] = right->child[i];
	}
	left->child[left_n + right->n] = right->child[right->n];
	free(right);
	return left;
	//left->child[left_n + right->n] = right->child[right->n];

}

tree_t *b_tree_create(void)
{
	bnode_t *new_node = create_node();
	tree_t *new_tree = (tree_t *)malloc(sizeof(tree_t));
	new_tree->root = new_node;
	return new_tree;
}
btree_result_t b_tree_search(bnode_t *node, int key)
{
	int i = 1;
	btree_result_t result = { NULL, 0 };
	while (i <= node->n && key > node->key[i - 1])
		i += 1;
	if (i <= node->n && key == node->key[i - 1])
	{
		result = { node, i - 1 };
		return result;
	}
	if (node->leaf)
		return result;
	else
	{
		bnode_t *ci = disk_read(node->child[i]);
		return b_tree_search(ci, key);
	}

}
btree_result_t btree_search_no_accurate(bnode_t *node, int key)
{
	int i = 0;
	btree_result_t result = { NULL, 0 };
	while (i < node->n && key > node->key[i])
		i++;
	if (key == node->key[i])
		result = { node, i };
	return result;
}
//some problems with successor and decessor
btree_result_t btree_predecessor(bnode_t *node, int key)
{
	int i = 0;
	btree_result_t result = { NULL, 0 };
	while (i < node->n && key > node->key[i])
		i++;
	if (i == node->n || i == 0)
		return result;
	if (node->leaf)
	{
		result = { node, i - 1 };
		return result;
	}
	node = node->child[i];
	while (node->leaf == false)
		node = node->child[node->n];
	return{ node, node->n - 1 };
}
btree_result_t btree_successor(bnode_t *node, int key)
{
	int i = 0;
	while (i < node->n && key > node->key[i])
		i++;
	if (node->leaf)
		return{ node, i + 1 };
	node = node->child[i + 1];
	while (node->leaf == false)
		node = node->child[0];
	return{ node, 0};
}
void b_tree_split_child(bnode_t *node, int index, bnode_t *child_node, int degree)
{
	bnode_t *new_node = create_node();
	new_node->leaf = child_node->leaf;
	new_node->n = degree - 1;
	for (int j = 0;j < degree - 1; j++)
		new_node->key[j] = child_node->key[j + degree];
	if (!child_node->leaf)
	{
		for (int j = 0;j < degree;j++)
			new_node->child[j] = new_node->child[j + degree];
	}
	child_node->n = degree - 1;
	for (int j = node->n; j >= index + 1; j--)
		node->child[j + 1] = node->child[j];
	node->child[index + 1] = new_node;
	for (int j = node->n - 1;j >= index; j--)
		node->key[j + 1] = node->key[j];
	node->key[index] = child_node->key[degree - 1];
	node->n += 1;
	disk_write(child_node);
	disk_write(new_node);
	disk_write(node);
}
void b_tree_insert_nonfull(bnode_t *node, int k, int degree)
{
	int i = node->n - 1;
	if (node->leaf)
	{
		while (i >= 0 && k < node->key[i])
		{
			node->key[i + 1] = node->key[i];
			i -= 1;
		}
		node->key[i + 1] = k;
		node->n += 1;
		disk_write(node);
	}
	else
	{
		while (i >= 0 && k < node->key[i])
			i -= 1;
		i += 1;
		disk_read(node->child[i]);
		bnode_t *child = disk_read(node->child[i]);
		if (child->n == 2 * degree - 1)
		{
			b_tree_split_child(node, i, child, degree);
			if (k > node->key[i])
			{
				i += 1;
				child = disk_read(node->child[i]);
			}
		}
		b_tree_insert_nonfull(child, k, degree);
	}
}

void b_tree_insert(tree_t *T, int k)
{
	bnode_t *r = T->root;
	if (r->n == 2 * T->degree - 1)
	{
		bnode_t *new_node = create_node();
		T->root = new_node;
		new_node->leaf = false;
		new_node->n = 0;
		new_node->child[0] = r;
		b_tree_split_child(new_node, 0, r, T->degree);
		b_tree_insert_nonfull(new_node, k, T->degree);
	}
	else
		b_tree_insert_nonfull(r, k, T->degree);
}
bool b_tree_delete(bnode_t *node, int key, int degree)
{
	//search
	int i = 0;
	while (i < node->n && key > node->key[i])
		i++;
	if (i == node->n)
		return false;
	if (key == node->key[i])
	{
		if (node->leaf)
		{
			//case 1
			for (; i < node->n; i++)
			{
				node->key[i] = node->key[i + 1];
				node->n -= 1;
			}
		}
		else
		{
			//case 2
			if (node->child[i]->n >= degree)
			{
				//case 2a
				btree_result_t result = btree_predecessor(node, key);
				node->key[i] = result.node->key[result.key_index];
				b_tree_delete(result.node, result.node->key[result.key_index], degree);
			}
			else if(node->child[i + 1]->n >= degree)
			{
				//case 2b
				btree_result_t result = btree_predecessor(node, key);
				node->key[i] = result.node->key[result.key_index];
				b_tree_delete(result.node, result.node->key[result.key_index], degree);
			}
			else
			{
				//case 2c both ci && ci - 1 have only degree - 1 keys
				bnode_t *merge_node = btree_merge(node->child[i], node->child[i + 1], key);
				for (int j = i;j < node->n;j++)
					node->key[j] = node->key[j + 1];
				node->child[i] = merge_node;
				for (int j = i + 1;j <= node->n; j++)
					node->child[j] = node->child[j + 1];
				node->n -= 1;
				b_tree_delete(merge_node, key, degree);
			}
		}
		return true;
	}
	else
	{
		bnode_t *children = node->child[i];
		int delete_key;
		if (children->n == degree - 1)
		{
			bnode_t *sibling = (i == node->n ? node->child[i - 1] : node->child[i + 1]);
			if (sibling->n == degree - 1)
			{
				
				bnode_t *merge_node = btree_merge(children, sibling, node->key[i]);
				if (i != node->n)
				{
					for (int j = i;j < node->n;j++)
						node->key[j] = node->key[j + 1];
					node->child[i] = merge_node;
					for (int j = i + 1;j <= node->n; j++)
						node->child[j] = node->child[j + 1];
					node->n -= 1;
				}
				else
				{
					node->key[node->n - 1] = node->key[node->n];
					node->child[node->n - 1] = merge_node;
					node->child[node->n] = node->child[node->n + 1];
					node->n -= 1;
					
				}
				b_tree_delete(merge_node, key, degree);
			}
			else
			{
				if (i != node->n)
				{
					delete_key = sibling->key[0];
					for (int j = 0;j < sibling->n;j++)
					{
						sibling->key[j] = sibling->key[j + 1];
						sibling->child[j] = sibling->child[j + 1];
					}
					sibling[sibling->n] = sibling[sibling->n + 1];
					sibling->n -= 1;

					children->key[children->n + 1] = node->key[i];
					children->n += 1;

				}
				else
				{
					delete_key = sibling->key[sibling->n - 1];
					sibling->key[sibling->n - 1] = sibling->key[sibling->n];
					sibling->child[sibling->n] = sibling->child[sibling->n + 1];
					sibling->n -= 1;

					for (int j = children->n;j > 0;j--)
					{
						children->key[j] = children->key[j - 1];
					}
					children->n += 1;
					children->key[0] = node->key[i];
				}
				node->key[i] = delete_key;
				b_tree_delete(children, key, degree);
			}
		}
		b_tree_delete(children, key, degree);
		return true;
	}
	
}


int main(void)
{
	tree_t *new_tree = b_tree_create();
}