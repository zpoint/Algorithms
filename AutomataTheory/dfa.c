#include <stdio.h>

enum STATE {A, B, C};

enum STATE T_A(char c)
{
		if (c == '0')
				return B;
		else // c == '1'
				return C;
}

enum STATE T_B(char c)
{
		return B;
}

enum STATE T_C(char c)
{
		return C;
}

int main()
{
		int c;
		enum STATE current_state = A;
		printf("Please enter strings only contains 0, 1, I will match all string start with 0\n");
		while ((char)(c = getchar()) != EOF)
		{
				if (c == '\n')
				{
						if (current_state == B)
								printf("In the accepted state\n");
						else
								printf("Not accepted\n");

						current_state = A;
						continue;
				}
				if (current_state == A)
						current_state = T_A(c);
				else if (current_state == B)
						current_state = T_B(c);
				else // current_state == C
						current_state = T_C(c);
		}
		return 0;
}
