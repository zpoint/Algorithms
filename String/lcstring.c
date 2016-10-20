#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void pr_matrix(int **matrix, int alen, int blen)
{
		for (int i = 0; i <= blen; i++)
		{
				for (int j = 0; j <= alen; j++)
				{
						printf("%d\t", matrix[i][j]);
				}
				printf("\n");
		}
}


char *lcstring(char *str1, char *str2)
{
		int alen = strlen(str1);
		int blen = strlen(str2);
		int maxi, maxj, currval, maxval = 0, k = 0;

		int **matrix = malloc(sizeof(int *) * (blen + 1));
		for (int i = 0; i <= blen; i++)
		{
				*(matrix + i) = malloc(sizeof(int) * (alen + 1));
				memset(*(matrix + i), 0, sizeof(int) * (alen + 1));
		}
		for (int i = 1; i <= blen; i++)
		{
				for (int j = 1; j <= alen; j++)
				{
						if (str1[j - 1] == str2[i - 1])
						{
								currval = matrix[i - 1][j - 1] + 1;
								if (currval > maxval)
									{ maxval = currval; maxi = i; maxj = j; }
								matrix[i][j] = currval;
						}
				}
		}
		//pr_matrix(matrix, alen, blen);

		char *s = malloc(sizeof(char) * (maxval + 1));
		k = maxval - 1;
		for (; maxi > 0 && maxj > 0; maxi--, maxj--)
		{
				s[k--] = str2[maxi - 1];
		}
		s[maxval] = '\0';
		return(s);
}

int main(int argc, char *argv[])
{
		char a[] = "tutorialhorizon";
		char b[] = "dynamictutorialProgramming";
		char *c = lcstring(a, b);
		printf("stringA:\t%s\nstringB:\t%s\nlcstring:\t%s\nlength: \t%ld\n", a, b, c, strlen(c));
		return(0);
}

