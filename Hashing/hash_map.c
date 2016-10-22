// a-zA-Z  65-122 in ascii
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORDSIZ sizeof(long) * 8
#define VALERR 0
typedef char kmap_t; // key type
typedef int msize_t; // size of hashtable
typedef int val_t;  

typedef struct Vmap_t
{
		struct Vmap_t *prev;
		val_t value;
		kmap_t key;
		struct Vmap_t *next;
}vmap_t;


typedef struct hashtable_t
{
		msize_t size;
		msize_t capacity;
		vmap_t *arr[]; // array of value
}Htable_t;

int resizetable(Htable_t *, int);
Htable_t *init_hashtable(void)
{
		Htable_t *new_table = malloc(sizeof(Htable_t));
		new_table->size = 0;
		new_table->capacity = 1;
		*new_table->arr = malloc(sizeof(vmap_t));
		*new_table->arr = NULL;
		return(new_table);
}

msize_t hashfunc(Htable_t *table, kmap_t key)
{
		/* Below not work as expected, too many collision
		// return index of an array
		static int r = 34; // change r to modify index range
		long index = ((RAND * (int)key) % (unsigned long)-1) >> r;
		printf("%ld\n", index);
		return(0);
		*/
		return(key % table->capacity);

}

int hashmap(Htable_t *table, kmap_t key, kmap_t val)
{
		// map the key to table, return 1 in success
		vmap_t *tmp, *new_v, *parent_tmp;
		if (table->size == table->capacity)
				resizetable(table, 1);
		msize_t index = hashfunc(table, key);
		if (table->arr[index] == NULL)
		{
				new_v = malloc(sizeof(vmap_t));
				new_v->value = val;
				new_v->key = key;
				new_v->prev = NULL;
				new_v->next = NULL;
				table->arr[index] = new_v;
		}
		else
		{
				tmp = table->arr[index];
				while (tmp != NULL)
				{
						if (tmp->key == key)
						{
								tmp->value = val;
								return(1);
						}
						parent_tmp = tmp;
						tmp = tmp->next;
				}
				new_v = malloc(sizeof(vmap_t));
				new_v->value = val;
				new_v->key = key;
				new_v->prev = tmp;
				tmp->next = new_v;
				new_v->next = NULL;
		}
		table->size++;
		return(1);
}	

int rehash(Htable_t *table, vmap_t *tmp, msize_t i)
{
		if (tmp->prev == NULL && tmp->next == NULL)
				table->arr[i] = NULL;
		else if (tmp->prev == NULL)  // tmp->next != NULL
		{
				table->arr[i] = tmp->next;
				tmp->next->prev = NULL;
		}
		else if (tmp->next == NULL) // tmp->prev != NULL
				tmp->prev->next = NULL;
		else
		{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
		}
		table->size--;
		hashmap(table, tmp->key, tmp->value);
		free(tmp);
		return(1);
}

int resizetable(Htable_t *table, int cmd)
{
		// cmd == 1, resize to a bigger table
		// cmd == 0, resize to a smaller table, caller already check, no need to check again
		vmap_t *tmp, *next;
		msize_t i, old_capacity, half_capacity;
		old_capacity = table->capacity;
		half_capacity = table->capacity / 2;
		if (cmd == 1)
		{
				*table->arr = realloc(*table->arr, sizeof(vmap_t) * (table->capacity * 2));
				memset(*table->arr + table->capacity, 0, sizeof(vmap_t) * table->capacity);
				table->capacity *= 2;
				for (i = 0; i < old_capacity; i++)
				{
						if ((tmp = table->arr[i]) == NULL)
								continue;
						while (tmp != NULL)
						{
								next = tmp->next;
								if (hashfunc(table, tmp->key) != i)
								{
										// del tmp and rehash
										rehash(table, tmp, i);
								}
								tmp = next;
						}
				}
				return(1);
		}					
		else if (cmd == 0)
		{
				table->capacity = half_capacity;
				for (i = 0; i < old_capacity; i++)
				{
						if ((tmp = table->arr[i]) == NULL)
								continue;
						while (tmp != NULL)
						{
								next = tmp->next;
								if (i >= half_capacity || hashfunc(table, tmp->key) != i)
								{
										// del tmp and rehash
										rehash(table, tmp, i);
								}
								tmp = next;
						}
				}
				*table->arr = realloc(*table->arr, sizeof(vmap_t) * half_capacity);
				return(1);
		}
		return(0);
}

val_t hashget(Htable_t *table, kmap_t key)
{
		msize_t index = hashfunc(table, key);
		vmap_t *tmp = table->arr[index];
		while (tmp != NULL)
		{
				if (tmp->key == key)
						return(tmp->value);
				tmp = tmp->next;
		}
		return(VALERR);
}

int hashdelete(Htable_t *table, kmap_t key)
{
		msize_t index = hashfunc(table, key);
		vmap_t *tmp = table->arr[index];
		while (tmp != NULL)
		{
				if (tmp->key == key)
				{
						if (tmp->next == NULL && tmp->prev == NULL)
								table->arr[index] = NULL;
						else if (tmp->prev == NULL)
						{
								table->arr[index] = tmp->next;
								tmp->next->prev = NULL;
						}
						else if (tmp->next == NULL)
								tmp->prev->next = NULL;
						else
						{
								tmp->prev->next = tmp->next;
								tmp->next->prev = tmp->prev;
						}
						free(tmp);
						table->size -= 1;
						//printf("table.size: %d, capacity: %d\n", table->size, table->capacity);
						//resizetable(table, 0);
						return(1);
				}
				tmp = tmp->next;
		}
		return(0);
}
/*
		if (table->size < table->capacity)
				resizetable(table, 0);
		return(1);
		*/


int main(int argc, char *argv[])
{
		Htable_t *table = init_hashtable();
		hashmap(table, 'c', 9);
		printf("size: %d, capacity: %d\n",  table->size, table->capacity);
		hashmap(table, 'd', 10);
		printf("size: %d, capacity: %d\n",  table->size, table->capacity);
		hashmap(table, 'c', 11);
		printf("size: %d, capacity: %d\n",  table->size, table->capacity);
		printf("delete c:\t%d\n", hashdelete(table, 'c'));
		printf("hashget(table, c): %d\thashget(table, d):%d\n", hashget(table, 'c'), hashget(table, 'd'));
		return(0);
}
