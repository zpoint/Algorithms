#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <string.h>
int min(int a, int b, int c)
{
		if (a <= b && a <= c)
				return(a);
		else if (b <= c && b <= a)
				return(b);
		else
				return(c);
}


int editDistanceRecursive(char *arra, char *arrb, int asize, int bsize)
{
		if (asize == 0)
				return(bsize);
		if (bsize == 0)
				return(asize);
		int tmp = 1;
		if (arra[asize - 1] == arrb[bsize - 1])
				tmp = 0;
		return(min(editDistanceRecursive(arra, arrb, asize-1, bsize-1) + tmp,
				   editDistanceRecursive(arra, arrb, asize-1, bsize) + 1,
				   editDistanceRecursive(arra, arrb, asize, bsize-1) + 1));
}


int editDistance(char *arra, char *arrb, int asize, int bsize)
{
		int return_val, prev;
		int **matrix = malloc(sizeof(int *) * (asize + 1));
		for (int i = 0; i <= asize; i++)
		{
				*(matrix + i) = malloc(sizeof(int) * (bsize + 1));
				memset(*(matrix + i), 0, sizeof(int) * (bsize + 1));
		}
		for (int i = 1; i <= asize; i++)
				**(matrix + i) = i;
		for (int i = 1; i <= bsize; i++)
				*((*matrix) + i) = i;
		for (int i = 1; i <= asize; i++)
				for (int j = 1; j <= bsize; j++)
				{
						if (arra[i - 1] == arrb[j - 1])
								prev = 0;
						else
								prev = 1;
						*(*(matrix + i) + j) = min(*(*(matrix + i) + j) + prev,
												   *(*(matrix + i - 1) + j) + 1,
												   *(*(matrix + i) + j -1) + 1);
				}
		return(*(*(matrix + asize) + bsize));
}

int main(void)
{
		int result;
		struct timeb ts1, ts2;
		ftime(&ts1);
		char *a = "Oh my gooiidood";
		char *b = "hh mv gooioeoid";
		printf("\n\t\t%s\n\t\t%s\n\t\tCalling editDistanceRecursive:\n\t\t", a, b);
		result = editDistanceRecursive(a, b, strlen(a), strlen(b));
		ftime(&ts2);
		printf("Result: %d, Cost: %lf seconds\n\t\t", result, (double)((ts2.time - ts1.time) * 1000 + (ts2.millitm - ts1.millitm)) / 1000.0);
		printf("Calling Dynamic Programming editDistance:\n\t\t");
		ftime(&ts1);
		editDistance(a, b, strlen(a), strlen(b));
		ftime(&ts2);
		printf("result: %d, Cost: %lf seconds\n", result, (double)((ts2.time - ts1.time) * 1000 + (ts2.millitm - ts1.millitm)) / 1000.0);
		return(0);
}
