#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/timeb.h>

int test_prime(int x)
{
		if (x <= 1)
				return(0);
		int flag = 0;
		for (int i = 2; i * i <= x; i++)
				if (x % i == 0)
				{
						flag = 1;
						break;
				}
		if (flag == 0)
				return(1);
		return(0);
}


int generate_prime()
{
		int prime;
		do
		{
				prime = rand() % 10;
		}
		while (test_prime(prime) != 1);
		return(prime);
}

int hashchr(char a, int prime, int position) // position start from 0
{
		unsigned long long  num = (int)a;
		for (int i = position; i > 0; i--)
				num *= prime;
		return(num);
}

unsigned long long hashstr(char *a, int prime, int length)
{
		unsigned long long val = 0;
		for (int i = 0; i < length; i++)
				val += hashchr(*(a+i), prime, i);
		return(val);
}

unsigned long long hashshiftR(char *start, int prime, int length, unsigned long long val)
{
		//printf("val before -: %ld\n", val);
		val -= hashchr(*start, prime, 0);
		//printf("val: %ld\n", val);
		val /= prime;
		//printf("prime: %d, val: %ld\n", prime, val);
		val += hashchr(*(start + length), prime, length - 1);
		return(val);
}

unsigned long long hashstr2(char *a, int prime, int length)
{
		unsigned long long val = 0;
		for (int i = 0; i < length; i++)
				val += *(a + i) % prime;
		return(val);
}

unsigned long long hashshiftR2(char *start, int prime, int length, unsigned long long val)
{
		val -= *start % prime;
		val += *(start + length) % prime;
		return(val);
}

int mystrcmp(char *a, char *b, int length)
{
		for (int i = 0; i < length; i++)
		{
				if (*(a + i) != *(b + i))
						return(i + 1);
		}
		return(0);
}

int KR_string(char *arra, char *arrb, int alen, int blen)  // search b in a, a is the longer
{
		if (blen > alen)
				return(-1);
		srand(time(NULL));
		int prime = generate_prime();
		unsigned long long hasha = hashstr2(arra, prime, blen);
		unsigned long long hashb = hashstr2(arrb, prime, blen);
		if (hasha == hashb && mystrcmp(arra, arrb, blen) == 0)
				return(0);
		for (int i = 0; i < (alen - blen); i++)
		{
				hasha = hashshiftR2(arra + i, prime, blen, hasha);
				//printf("i+1: %d, hasha: %ld, hashb: %ld, newhashb: %ld, newhasha: %ld\n", i+1, hasha, hashb, hashstr(arrb, prime, blen), hashstr(arra + i + 1, prime, blen));
				if (hasha == hashb && mystrcmp(arra + i + 1, arrb, blen) == 0)
						return(i + 1);
		}
		return(-1);
}

int normal_search(char *arra, char *arrb, int alen, int blen)
{
		for (int i = 0; i <= (alen - blen); i++)
		{
				if (mystrcmp(arra + i, arrb, blen) == 0)
						return(i);
		}
		return(-1);
}


int main(int argc, char *argv[])
{
		/* Hashshift will overflow if cbar b[] is too long, seperate it and recursive search */
		struct timeb ts1, ts2;
		char a[] =  "ATGCUAGCSDSFDFDFDFGFBGVCBCXVCSDFDSFDSFTRTGRYFGHDFGDFGCXVXVCXFVCXVCXVCXVCXVXXCXCVVCXVFGHFHGJGHJHKJHKHJMKHJKMHNVBNVCNBVCBCVB1234567890123456789000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ATGCUAGCSDSFDFDFDFGFBGVCBCXVCSDFDSFD"
"SFTRTGRYFGHDFGDFGCXVXVCXFVCXVCXVCXVCXVXXCXCVVCXVFGHFHGJGHJHKJHKHJMKHJKMHNVBNVCNBVCBCVB12345678901234567890000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000012344SFTRTGRYGHDFGDFGCXVXVCXFVCXVCXVCXVCXVXXCXCVVCXVFGHFHGJGHJHKJHKHJMKHJKMHNVBNV"
"CNBVCBCVB12345678901234567890000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000123445";
		//char a[] = "A12345678900";
		char b[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000123445";
		ftime(&ts1);
		int result = KR_string(a, b, strlen(a), strlen(b));
		ftime(&ts2);
		printf("result: %d, Took %lf seconds\n", result, (double)(((ts2.time - ts1.time) * 1000 + (ts2.millitm - ts1.millitm)) / 1000.0));
		ftime(&ts1);
		result = normal_search(a, b, strlen(a), strlen(b));
		ftime(&ts2);
		printf("result: %d, Took %lf seconds\n", result, (double)(((ts2.time - ts1.time) * 1000 + (ts2.millitm - ts1.millitm)) / 1000.0));
		return(0);
}
