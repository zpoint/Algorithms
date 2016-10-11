#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct string_t
{
	char *start;
	unsigned int length;
}string;
typedef struct int_arr_t
{
	int *start;
	unsigned int length;
}int_arr;
int hash(string *str, int prime)
{
	int j = 0;
	int d = 1;
	for (unsigned int i = 0;i < str->length;i++)
	{
		j += d * int(str->start[i]);
		d *= prime;
	}
	return j;
}

void rabin_karp_matcher(string *T, string *pattern, int prime)
{
	unsigned int Tlength = T->length;
	unsigned int Plength = pattern->length;
	int highest_digit = 1;
	for (unsigned int i = 0; i < Plength - 1; i++)
		highest_digit *= prime;
	int hash_p = hash(pattern, prime);
	string str = { T->start, Plength };
	int hash_t = hash(&str, prime);
	for (unsigned int i = 0; i <= Tlength - Plength; i++)
	{
		printf("hash_t:%d\thash_p:%d\n", hash_t, hash_p);
		if (hash_t == hash_p)
		{
			int match = true; //true
			for (unsigned int j = 0; j < Plength;j++)
			{
				if (pattern->start[j] != T->start[i + j])
				{
					match = false; //false
					break;
				}
			}
			if (match)
			{
				printf("Pattern occurs with shift %d\n", i);
				printf("%s\n",T->start);
				for (unsigned int k = 0;k < i;k++)
					printf(" ");
				printf("%s\n", pattern->start);
			}
		}
		if (i < Tlength - Plength)
		{
			hash_t -= int(T->start[i]);
			hash_t /= prime;
			hash_t += int(T->start[i + Plength]) * highest_digit;
		}
	}
}

int_arr compute_prefix_function(string *pattern)
{
	unsigned plength = pattern->length;
	int *arr = (int *)malloc(sizeof(int) * plength);
	int_arr predecessor = { arr , plength };
	arr[0] = 0;
	int k = 0;
	for (unsigned int i = 1;i < plength;i++)
	{
		while (k > 0 && pattern->start[k] != pattern->start[i])
		{
			k = arr[k - 1];
		}
		if (pattern->start[k] == pattern->start[i])
			k += 1;
		arr[i] = k;
	}
	return predecessor;
}
void kmp_match(string *T, string *pattern)
{
	unsigned tlength = T->length;
	unsigned plength = pattern->length;
	int_arr predecessor = compute_prefix_function(pattern);
	unsigned match_index = 0;
	for (unsigned int i = 0; i < tlength; i++)
	{
		while (match_index > 0 && pattern->start[match_index] != T->start[i])
			match_index = predecessor.start[match_index - 1];
		printf("match_index:%d\t i:%d\n", match_index, i);
		if (pattern->start[match_index] == T->start[i])
			match_index += 1;
		if (match_index == plength - 1 && pattern->start[match_index] == T->start[i + 1])
		{
			printf("Pattern occurs with shift %d\n", i + 3 - plength);
			printf("%s\n", T->start);
			for (unsigned int k = 0;k < i + 2 - plength;k++)
				printf(" ");
			printf("%s\n", pattern->start);
			match_index = predecessor.start[match_index];
		}
	}
}

int main(void)
{
	string t = { "abxabcabcaby", 12 };
	string pattern = { "abcaby", 6 };
	//rabin_karp_matcher(&t, &pattern, 11);
	kmp_match(&t, &pattern);
	return 0;
}