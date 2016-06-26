/*
Perfect cubes in a range
: Hash
: Ref. to Primes
*/

#include <stdio.h>
#define MAX_PC 10001

int PC[MAX_PC];

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i, a, b, cnt;

	// generate perfect cubes via hash
	for (i = 1; (i*i*i) < MAX_PC; i++)
		PC[i*i*i]++;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &a, &b);
		
		cnt = 0;
		for (i = a; i <= b; i++)
		{
			if (PC[i])
			{
				cnt++;
				printf("%d ", i);
			}
		}

		if (cnt > 0)
			printf("\n cnt = %d\n", cnt);
		else
			printf("No\n");
	}

	return 0;
}
