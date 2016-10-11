#include <stdio.h>
typedef struct euclid_type
{
	int d;
	int x;
	int y;
}euclid_t;
euclid_t extended_euclid(int a, int b)
{
	if (b == 0)
	{
		printf("%d\t%d\t\t%d\t%d\t%d\t\n", a, b, a, 1, 0);
		return{ a, 1, 0 };
	}
	euclid_t tuple = extended_euclid(b, a % b);
	printf("%d\t%d\t\t%d\t%d\t%d\t\n", a, b, tuple.d, tuple.y, tuple.x - tuple.y * (a / b));
	return{ tuple.d, tuple.y, tuple.x - tuple.y * (a / b) };
}
int extended_euclid_none_recursive(int a, int b)
{
	int old_a = a, old_b = b, temp;
	while (old_b != 0)
	{
		temp = a;
		a = b;
		b = temp % b;
		printf("a:%d\tb:%d\told_a:%d\told_b:%d\t\n", a, b, old_a, old_b);
		old_b = b;
		old_a = a;
	}
	return a;
}
int main(void)
{
	extended_euclid(899, 493);
	extended_euclid_none_recursive(899, 493);
	return 0;
}