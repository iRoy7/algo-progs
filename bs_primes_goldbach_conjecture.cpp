/*
Goldbach Conjecture
6 = 3 + 3
8 = 3 + 5
10 = 3 + 7 = 5 + 5
12 = 7 + 5
...
100 = 3 + 97 = 11 + 89 = 17 + 83 = 29 + 71 = 41 + 59 = 47 + 53
...

*/

#include <stdio.h>
#define MAX_NP 1001

int NP[MAX_NP];
int HT[MAX_NP];

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i, j, N;

	// generate primes
	NP[0] = NP[1] = 1;
	for (i = 2; (i*i) < MAX_NP; i++)
		if (!NP[i])
			for (j = (i*i); j < MAX_NP; j += i)
				NP[j] = 1;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		// i should be a prime and odd number.
		for  (i = 3; i <= N; i += 2)
		{
			if (!NP[i] && !NP[N - i])
			{
				if (!HT[i] && !HT[N - i])
				{
					HT[i]++, HT[N - i]++;
					printf("%d = %d + %d\n", N, i, N - i);
				}				
			}
		}

		// clear hash table
		for (i = 0; i < MAX_NP; i++)
			HT[i] = 0;
	}

	return 0;
}
