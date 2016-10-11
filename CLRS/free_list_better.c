#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
typedef int list_t;
typedef int obj_t;

int empty_obj = -1;
int empty_list = -1;
int cells[MAX_SIZE * 3];
int free_list;

#define NEXT(i) cells[i * 3]
#define KEY(i) cells[i * 3 + 1]
#define PREV(i) cells[i * 3 + 2]

void init_storage()
{
	int i;
	for (i = 0; i < MAX_SIZE - 1; i++)
		NEXT(i) = i + 1;
	NEXT(i) = empty_list;
	free_list = 0;
}

list_t allocate_object()
{
	if (free_list < 0)
	{
		fprintf(stderr, "storage depleted!!\n");
		exit(0);
	}
	list_t new_list = free_list;
	free_list = NEXT(free_list);
	return new_list;
}

void free_object(list_t target_list)
{
	NEXT(target_list) = free_list;
	free_list = target_list;
}

list_t cons(obj_t new_obj, list_t target_list)
{
	list_t new_list = allocate_object();
	KEY(new_list) = new_obj;
	PREV(new_list) = empty_list;
	printf("PREV(new_list:%d)%d\n", new_list, PREV(new_list));
	NEXT(new_list) = target_list;
	printf("NEXT(new_list:%d)%d\n", new_list, NEXT(new_list));

	if (target_list != empty_list)
		PREV(target_list) = new_list;
	return new_list;
}

void delete_list(list_t *target_list_ptr)
{
	list_t target_list = *target_list_ptr;
	printf("target_list:%d\n", target_list);
	printf("PREV(target_list)%d\n", PREV(target_list));
	printf("NEXT(target_list)%d\n", NEXT(target_list));
	if (target_list == empty_list)
	{
		fprintf(stderr, "Cannot delete empty list\n");
		exit(0);
	}
	if (PREV(target_list) != empty_list)
		NEXT(PREV(target_list)) = NEXT(target_list);

	if (NEXT(target_list) != empty_list)
		PREV(NEXT(target_list)) = PREV(target_list);
	
	*target_list_ptr = NEXT(target_list);
	free_object(target_list);
}

obj_t get(list_t target_list)
{
	if (target_list == empty_list)
	{
		printf("Empty list!\n");
		return empty_obj;
	}
	return KEY(target_list);
}

list_t next(list_t target_list)
{
	if (target_list == empty_list)
	{
		printf("Empty list!\n");
		return empty_list;
	}
	return NEXT(target_list);
}

int main(void)
{
	init_storage();
	list_t list = empty_list;
	list = cons(101, list);
	list = cons(102, list);
	list = cons(103, list);
	list = cons(104, list);
	printf("\n\nbefore delete list: %d\n", list);
	delete_list(&list);
	printf("\n\nafter delete list: %d\n\n", list);
	list = cons(105, list);
	printf("list:%d\n", list);
	printf("PREV:list:%d\n", PREV(list));
	printf("NEXT:list:%d\n", NEXT(list));
	list = cons(106, list);
	printf("list:%d\n", list);
	printf("PREV:list:%d\n", PREV(list));
	printf("NEXT:list:%d\n", NEXT(list));
	//list = cons(107, list);
	while (list != empty_list)
	{
		printf("before:list:%d\n", list);
		printf("obj:%d\n", get(list));
		list = next(list);
		printf("after:list:%d\n", list);
	}
	return 0;
}