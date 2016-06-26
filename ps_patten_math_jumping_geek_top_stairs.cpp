/*
Pattern:
0 1 3 6 7 9 12 13 15 18 19 21 24 ...

-> 6 12 18 24

In case of following three cases,
x % 6 == 0
x % 6 == 3
x % 6 == 1 

Reach to the top stairs.

*/

#include <stdio.h>

int main()
{
	setbuf(stdout, NULL);

	int T, tc;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		long long D;

		scanf("%lld", &D);

		if ((D % 6LL == 0LL)
			|| (D % 6LL == 3LL)
			|| (D % 6LL == 1LL))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
