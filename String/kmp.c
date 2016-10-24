#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *generate_prefix(char *arr, int length)
{
		int *ret_arr = malloc(sizeof(int)*length);
		ret_arr[0] = 0;
		int j = 0;
		int i = 1;
		while (i < length)
		{
				if (arr[i] == arr[j])
						ret_arr[i++] = ++j;
				else if (j == 0)
						ret_arr[i++] = j;
				else
						j = ret_arr[j-1];
		}
		return(ret_arr);
}

int KMP(char *string, char *substr, int len_str, int len_sub)
{
		int *prefix_arr = generate_prefix(substr, len_sub);
		int j = 0, i = 0;
		while (i < len_str)
		{
				if (string[i] == substr[j])
						{ j++; i++;}
				else if (j != 0)
						j = prefix_arr[j - 1];
			    else // j == 0 and string[i] != substr[j]
						i++;
				if (j == len_sub)
				{ printf("match in index: %d\n", i - len_sub); i = i - len_sub + 1; j = 0;}
		}
		free(prefix_arr);
		return(1);
}


int main(int argc, char*argv[])
{
		char a[] = "abxabcabcabyxxabcabyj";
		char b[] = "abcaby";
		printf("a: %s, b: %s\n", a, b);
		KMP(a, b, sizeof(a)-1, sizeof(b)-1);
		return(0);
}

