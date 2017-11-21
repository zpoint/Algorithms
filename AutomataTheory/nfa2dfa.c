#include <stdio.h>
#include <stdlib.h>

enum INPUTS {ZERO, ONE};

struct table
{
		size_t symbol_size;
		size_t input_size;
		char ***table_entry;
};

struct table init_nfa_table()
{
		// symbol A B C
		// input 0, 1
		struct table ndf_table;
		char ***table_entry = (char ***)malloc(sizeof(char ***) * 3);
		for (size_t i = 0; i < 3; ++i)
		{
				table_entry[i] = (char **)malloc(sizeof(char **) * 2);
				switch (i)
				{

				}
		}
}

int main()
{
		return 0;
}
