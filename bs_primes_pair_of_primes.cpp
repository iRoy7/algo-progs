/*
Pair of prime number

F(N) = (p * q) <= N

find p and q pairs

input:
2
4 
8
===============
output:
2 2
2 2 2 3 3 2
*/

#include <stdio.h>
#define MAX_NP 401

int NP[MAX_NP];
int N;

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i, j;

	// generate primes first
	NP[0] = NP[1] = 1;
	for (i = 2; (i*i) < MAX_NP; i++)
		if (!NP[i])
			for (j = (i*i); j < MAX_NP; j += i)
				NP[j] = 1;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		for (i = 2; i <= N; i++)
			for (j = 2; j <= N; j++)
				if (!NP[i] && !NP[j])
					if ((i*j) <= N)
						printf("%d %d ", i, j);
		printf("\n");
	}

	return 0;
}
