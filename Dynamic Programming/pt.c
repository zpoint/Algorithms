#include <stdio.h>
#include <string.h>
#define MAXN 20

void pr_be(int (*be)[MAXN])
{
		for (int i = 0; i < MAXN; i++)
		{
				for (int j = 0; j < MAXN; j++)
						printf("%-5d  ", be[i][j]);
				printf("\n\n");
		}
		putchar('\n');
}

int main(void)
{
		int be[MAXN][MAXN];
		memset(be, 0, MAXN * MAXN * sizeof(int));
		for (int i = 0; i < MAXN; i++) be[i][0] = 1;
		for (int j = 0; j < MAXN; j++) be[j][j] = 1;
		pr_be(be);
		for (int i = 0; i < MAXN; i++)
		{
				for (int j = 0; j < i; j++)
						be[i][j] = be[i-1][j-1] + be[i-1][j];
		}
		pr_be(be);
		return(0);
}
