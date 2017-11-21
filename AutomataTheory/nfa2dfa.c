#include <stdio.h>
#include <stdlib.h>

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
						case 0: // A
								table_entry[i][0] = "A";
								table_entry[i][1] = "AB";
								break;
						case 1: // B
								table_entry[i][0] = "C";
								table_entry[i][1] = "C";
								break;
						case 2:// C
								table_entry[i][0] = "~";
								table_entry[i][1] = "~";
				}
		}
		ndf_table.symbol_size = 3;
		ndf_table.input_size = 2;
		return ndf_table;
}

struct table to_dfa_table(struct table ndf_table)
{
		struct table dfa_table;

}

int main()
{
		return 0;
}
