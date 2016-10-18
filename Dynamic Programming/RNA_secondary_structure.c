#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pr_matrix(int **matrix, int size)
{
		printf("\t\t");
		for (int i = 0; i < size; i++)
		{
				printf("%2d: ", i+1);
				for (int j = 0; j < size; j++)
						printf("%2d ", *(*(matrix + i) + j));
				printf("\n\t\t");
		}
		printf("\n\t\t    ");
		for (int i = 0; i < size; i++)
				printf("%2d ", i+1);
		printf("\n");
}

int ismatch(char a, char b)
{
		if (a == 'A' && b == 'U')
				return(1);
		else if (a == 'U' && b == 'A')
				return(1);
		else if (a == 'G' && b == 'C')
				return(1);
		else if (a == 'C' && b == 'G')
				return(1);
		return(0);
}

int look_up(int **matrix, int start, int stop)
{
		int max = 0, sum;
		for (int k = start + 1; k < stop; k++)
		{
				sum = *(*(matrix + start) + k - 1) + *(*(matrix + k + 1) + stop);
				if (sum > max)
						max = sum;
		}
		return max;
}

int max(int a, int b)
{
		if (a > b)
				return(a);
		return(b);
}

void RNA_secondary_structure(char *str, int size)
{
		int i, j, k, match;
		int **matrix = malloc(sizeof(int *) * size);
		for (i = 0; i < size; i++)
		{
				*(matrix + i) = malloc(sizeof(int) * size);
				memset(*(matrix + i), 0, sizeof(int) * size);
		}
		for (k = 5; k < size; k++)
		{
				for (i = 0; i < size - k; i++)
				{
						j = i + k;
						match = ismatch(str[i], str[j]);
						*(*(matrix + i) + j) = max(*(*(matrix + i) + j - 1), match + look_up(matrix, i, j));
				}
		}
		pr_matrix(matrix, size);
}



int main(int argc, char *argv[])
{
		char *RNA = "ACCGGUAGUCGGAT";
		printf("\t\t%s\n", RNA);
		RNA_secondary_structure(RNA, strlen(RNA));
		return(0);
}
