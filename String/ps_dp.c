#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define True 0
#define False 1

int palindrome_substring(char *arr)
{
		int len = strlen(arr);
		int curr, middle, last, max_len = 0, max_lastIndex = 0, max_firstIndex = 0;
		int **matrix = malloc(sizeof(int) * len);
		for (int i = 0; i < len; i++)
		{
				*(matrix + i) = malloc(sizeof(int *) * len);
				memset(*(matrix + i), True, sizeof(int) * len);
		}
		for (int distance = 1; distance < len; distance++)
		{
				for (int i = 0; i + distance < len; i++)
				{
						last = i + distance;
						curr = arr[i] == arr[i+distance] ? True : False;
						if (distance == 1)
								middle = True;
						else
								middle = *(*(matrix + last - 1) + (i + 1));
						if (curr == True && middle == True)
						{
								if (distance + 1 > max_len)
								{max_len = distance + 1; max_lastIndex = last; max_firstIndex = i;}
								*(*(matrix + last) + i) = True;
						}
						else
								*(*(matrix + last) + i) = False;
				}
		}
		for (int i = max_firstIndex; i <= max_lastIndex; i++)
				putchar(arr[i]);
		return(max_len);
}



int main(int argc, char *argv[])
{
		int result;
		printf("\n\t\t");
		result = palindrome_substring("SSDSADCXVCBBMHJKJHKJHKTYGUTYUTRBANANA");
		printf("\n\t\tresult: %d\n", result);
		return(0);
}
