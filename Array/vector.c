#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define SIZE 16 // initial size
typedef int msize_t; // my size
typedef int item_t; // Define array type
#define ITEM_ERR 1 << 30 // return ERR_ITEM when fail to call function, assume INT_MAX not used
#define ITEM_EMY 0 // initial item value
typedef struct Vector_t
{
		msize_t size;
		msize_t capacity;
		item_t *array_ptr;
}vector_t;

item_t resize(vector_t *, msize_t);

vector_t *initial_vector()
{
		// Call initial_vector to malloc a vector
		item_t *array_ptr = (item_t *)malloc(sizeof(item_t) * SIZE);
		memset((void *)array_ptr, 0, sizeof(item_t) * SIZE);

		vector_t *vector_ptr = (vector_t *)malloc(sizeof(vector_t));
		vector_ptr->size = 0;
		vector_ptr->capacity = SIZE;
		vector_ptr->array_ptr = array_ptr;
		return vector_ptr;
}

void free_vector(vector_t *vector_ptr)
{
		free(vector_ptr->array_ptr);
		free(vector_ptr);
}

msize_t size(vector_t *vector_ptr)
{
		return vector_ptr->size;
}

msize_t capacity(vector_t *vector_ptr)
{
		return vector_ptr->capacity;
}

int is_empty(vector_t *vector_ptr)
{
		// Return 0 if False
		return (int)vector_ptr->size;
}

item_t at(vector_t *vector_ptr, msize_t index)
{
		if (index < 0 || index > vector_ptr->size - 1)
				return ITEM_ERR;
		return(vector_ptr->array_ptr[index]);
}

item_t push(vector_t *vector_ptr, item_t item)
{
		if (vector_ptr->size == vector_ptr->capacity)
				if (resize(vector_ptr, 2 * (vector_ptr->capacity)) == ITEM_ERR)
						return ITEM_ERR;
		vector_ptr->array_ptr[vector_ptr->size++] = item;
		//printf("adding: %d, size:%d\n", item, vector_ptr->size);
		return item;
}

item_t insert(vector_t *vector_ptr, msize_t index, item_t item)
{
		if (index >= vector_ptr->capacity || vector_ptr->size == vector_ptr->capacity)
		{
				if (resize(vector_ptr, index > 2 * (vector_ptr->capacity) ? index * 2 : 2 * (vector_ptr->capacity)) == ITEM_ERR)
						return ITEM_ERR;
				return insert(vector_ptr, index, item); // incase index too large, should set limit check here
		}
		if (index < vector_ptr->size) //  inserts item at index, shifts that index's value and trailing elements to the right
		{
				for (msize_t i = vector_ptr->size - 1; i >= index; i--)
				{
						vector_ptr->array_ptr[i] = vector_ptr->array_ptr[i -1];
				}
		}
		// if index > size and index < capacity, automatic increase the size to "index" position
		vector_ptr->array_ptr[index] = item;
		vector_ptr->size = index > vector_ptr->size ? index + 1 : vector_ptr->size + 1;
		return item;
}

item_t prepend(vector_t *vector_ptr, item_t item)
{
		return insert(vector_ptr, 0, item);
}

item_t pop(vector_t *vector_ptr)
{
	item_t return_item;
	if (vector_ptr->size == 0)
		   return ITEM_ERR;
	if (vector_ptr->size - 1 <= (vector_ptr->capacity >> 2)) // equal capacity / 4
			if (resize(vector_ptr, vector_ptr->capacity >> 1) == ITEM_ERR) // euqal capacity / 2
					return ITEM_ERR;

	return_item = vector_ptr->array_ptr[vector_ptr->size];
	vector_ptr->array_ptr[vector_ptr->size--] = ITEM_EMY; // set old index empty and cut size
	return return_item;
}

item_t delete(vector_t *vector_ptr, msize_t index)
{
		if (index >= vector_ptr->size)
				return ITEM_ERR;
		for (msize_t i = index; i < vector_ptr->size - 1; i++)
				vector_ptr->array_ptr[i] = vector_ptr->array_ptr[i + 1];
		return pop(vector_ptr);
}

item_t Remove(vector_t *vector_ptr, item_t item) // return ITEM_EMY if found and removed, ITEM_ERR not found, or other error
{
		// remove function declared in stdio.h, rename it with Remove
		if (vector_ptr->size == 0)
				return ITEM_ERR;
		msize_t count = 0; // count of item to be removed
		msize_t size = vector_ptr->size, capacity = vector_ptr->capacity;
		for (msize_t i = 0; i < size; i++)
		{
				if (vector_ptr->array_ptr[i] == item)
				{
						count++;
						continue;
				}
				if (count > 0) // not euqal, there are holes, shift left
						vector_ptr->array_ptr[i - count] = vector_ptr->array_ptr[i];
		}
		if (count > 0)
		{       // newszie = size - count
				// resize incase remove a huge amount of value
				if (size - count <= (capacity >> 2))
						if (resize(vector_ptr, (size - count) > (capacity >> 1) ? (size - count) : (capacity >> 1)) == ITEM_ERR)
							   return ITEM_ERR;	
				for (int i = size - count; i < size; i++)
						vector_ptr->array_ptr[i] = ITEM_EMY;
		}
		return ITEM_EMY;
}

msize_t find(vector_t *vector_ptr, item_t item)
{
		for (msize_t i = 0; i < vector_ptr->size; i++)
				if (vector_ptr->array_ptr[i] == item)
						return i;
		return -1;
}

item_t resize(vector_t *vector_ptr, msize_t new_capacity)
{
		if (new_capacity < 0)
				return ITEM_ERR;
		if ((vector_ptr->array_ptr = (item_t *)realloc(vector_ptr->array_ptr, new_capacity * sizeof(item_t))) == NULL)
		{
				free(vector_ptr);
				printf("malloc error, capacity and size will be wrong\n");
				return ITEM_ERR;
		}
		vector_ptr->capacity = new_capacity;
		return ITEM_EMY;
}

void pr_value(vector_t *vector_ptr)
{
		printf("\t\tsize: %d, capacity: %d, is_empty(): %d\n\t\ttraverse:\n\t\t", vector_ptr->size, vector_ptr->capacity, is_empty(vector_ptr));
		for (msize_t i = 0; i < vector_ptr->size; i++)
		{
				printf("%d\t", vector_ptr->array_ptr[i]);
				if (i != 0 && i % 10 == 0)
						printf("\n\t\t");
		}
		putchar('\n');
}

int main(void)
{
		srand(time(NULL));
		vector_t *vec_ptr = initial_vector();
		msize_t test_count = 200;
		printf("\t\tvector intialized\n");
		pr_value(vec_ptr);
		printf("\t\tAfter push %d random number between 0 - 100\n", test_count);
		for (item_t i = 0; i < test_count; i++)
				push(vec_ptr, rand() % 100);
		pr_value(vec_ptr);
		printf("\t\tAfter pop %d number\n", test_count / 2);
		for (item_t i = 0; i <test_count / 2; i++)
				pop(vec_ptr);
		pr_value(vec_ptr);
		printf("\t\tinsert 10 in %d, result: %d\n", test_count + 10, insert(vec_ptr, test_count + 10, 10));
		pr_value(vec_ptr);
		printf("\t\tfind 10:%d\n", find(vec_ptr, 10));
		pr_value(vec_ptr);
		printf("\t\tremove 10:%d\n", Remove(vec_ptr, 10));
		pr_value(vec_ptr);
		return 0;
}
