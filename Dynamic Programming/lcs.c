#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
		if (a > b)
				return(a);
		return(b);
}

void pr_matrix(int **matrix, int lena, int lenb)
{
		for (int i = 0; i <= lenb; i++)
		{
				for (int j = 0; j <= lena; j++)
						printf("%d  ", matrix[i][j]);
				printf("\n");
		}
}


char *pr_sequence(int **matrix, char *str1, char *str2, int lena, int lenb)
{
		pr_matrix(matrix, lena, lenb);
		int size = *(*(matrix + lenb) + lena);
		char *s = malloc(sizeof(char) * (size + 1));
		if (size == 0)
			{*s = '\0'; return(s);}
		*(s + size) = '\0';
		int i = lenb, j = lena, k = 0, up, left, corn, curr;
		while (j != 0 && i != 0)
		{
				left = *(*(matrix + i) + j - 1);
				up = *(*(matrix + i - 1) + j);
				corn = *(*(matrix + i - 1) + j - 1);
				curr = *(*(matrix + i) + j);
				//printf("i: %d, j: %d, curr: %d, left: %d, up: %d, corn: %d\n", i, j, curr, left, up, corn);
				if (curr == left)
						j -= 1;
				else if (curr == up)
						i -= 1;
				else
				{
						s[k++] = str2[i - 1];
						i -= 1;
						j -= 1;
				}
		}
		return(s);
}



char *LCS(char *str1, char *str2)
{
		int lena = strlen(str1);
		int lenb = strlen(str2);
		int **matrix = malloc(sizeof(int *) * (lenb + 1));
		for (int i = 0; i <= lenb; i++)
		{
				*(matrix + i) = malloc(sizeof(int) * (lena + 1));
				memset(*(matrix + i), 0, sizeof(int) * (lena + 1));
		}
		for (int i = 1; i <= lenb; i++) // i ---> vertical
		{
				for (int j = 1; j <= lena; j++) // j ---> hori
				{
						//printf("i: %d, j: %d, str2[i - 1]: %c, str1[j - 1]: %c\n", i, j, str2[i - 1], str1[j - 1]);
						if ( str2[i - 1] == str1[j - 1])
								*(*(matrix + i) + j) = *(*(matrix + i - 1) + j - 1) + 1;
						else
								*(*(matrix + i) + j) = max(*(*(matrix + i - 1) + j), *(*(matrix + i) + j - 1));
				}
		}
		char *s = pr_sequence(matrix, str1, str2, lena, lenb);
		for (int i = 0; i <= lenb; i++)
				free(*(matrix + i));
		free(matrix);
		return(s);
}	


int main(int argc, char *argv[])
{
		char a[] = "abcdeffff";
		char b[] = "acbcfff";
		char *c = LCS(a, b);
		int len = strlen(a);
		printf("%s\n%s\nResult:", a, b);
		int i = 0;
		while(c[i])
				printf("%c ", c[i++]);
		printf("\n");
		return(0);
}
