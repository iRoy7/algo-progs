#include <stdio.h>
int a[11];
inline int __print_n(int n)
{
	if (n == 0) return 0;
	else {
		printf("%d ", n);
		return __print_n(n - 1);
	}
}
inline int __recursion_fact(int n)
{
	if (n == 0 || n == 1) return 1;
	return n * __recursion_fact(n - 1);
}

int main()
{
	__print_n(10);
	int i;
	setbuf(stdout, NULL);
	// inputs:
	for (i = 0; i < 11; i++)
		scanf("%d", &a[i]);
	// factorials with recursion:
	for (i = 0; i < 11; i++)
		printf("%d\n", __recursion_fact(a[i]));

	return 0;
}
