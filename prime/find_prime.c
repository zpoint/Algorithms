#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#define PRIME 0
#define NOPRIME 1


void pr_prime(int *matrix, int size, int start)
{
		/*
		for (int i = 1; i <= size; i++)
		{
				printf("%d  " ,matrix[i - 1]);
				if (i % 10 == 0)
						printf("\n");
		}
		*/
		int count = 0;
		int addflag = 0;
		printf("\t\t");
		for (int i = 0; i < size; i++)
		{
				if (matrix[i] == PRIME)
				{
						printf("%-3d  ", start + i);
						count++;
						addflag = 1;
				}
				if (count % 10 == 0 && addflag == 1)
				{
						printf("\n\t\t");
						addflag = 0;
				}
		}
		printf("\n\t\tfrom %d to %d, Total: %d prime\n", start, start + size - 1, count);
}

int normal_prime(int start, int stop)
{
		//printf("\n\t\t");
		if (start < 1 || start > stop)
				return(-1);
		int flag;
		int count = 0;
		int num = start == 1 ? 2 : start;
		for (int i = num; i <= stop; i++)
		{
				flag = 1;
				for (int j = 2; j * j <= i; j++)
				{
						if (i % j == 0)				
								flag = 0;
				}
				if (flag == 1)
				{
						count++;
						//printf("%-3d  ", i);
						//if (count % 10 == 0)
						//		printf("\n\t\t");
				}
		}
		//printf("\n\t\t from %d to %d, Total: %d prime\n", start, stop, count);
		return(count);
}

int eratosh_prime(int start, int stop)  // [start, stop]
{
		if (start < 1)
				return(-1);
		int size = stop - start + 1;
		int num, count;
		int *matrix = malloc(sizeof(int) * size);
		memset(matrix, PRIME, sizeof(int) * size);
		if (start == 1)
		{
				matrix[0] = NOPRIME;
				num = 1;
		}
		else
				num = 0;
		for (int i = num; i < size; i++)
		{
				if (matrix[i] == PRIME)
				{
						++count;
						num = start + i;
						for (int j = num + num; j <= stop; j += num)
						{
								if (matrix[j - start] == PRIME)
										matrix[j - start]  = NOPRIME;
						}
				}
		}
		//pr_prime(matrix, size, start);
		free(matrix);
		return(count);
}

int main(int argc, char *argv[])
{
		int result;
		struct timeb ts1, ts2;
		ftime(&ts1);
		result = normal_prime(1, 9999999);
		ftime(&ts2);
		printf("\t\tnormal_prime:  from 1 to 9999999 result: %d, cost : %lf seconds\n", result, (double)(((ts2.time - ts1.time) * 1000 + (ts2.millitm - ts1.millitm)) / 1000.0));
		ftime(&ts1);
		result = eratosh_prime(1, 9999999);
		ftime(&ts2);
		printf("\t\teratosh_prime: from 1 to 9999999 result: %d, cost : %lf seconds\n", result, (double)(((ts2.time - ts1.time) * 1000 + (ts2.millitm - ts1.millitm)) / 1000.0));
		return(0);
}
