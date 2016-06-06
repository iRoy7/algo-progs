/*
input:
4
6
10 3 2 5 7 8
2
11 15
7
7 7 7 7 7 7 7
10
1 2 3 4 5 1 2 3 4 5
=======================
output:
19 | 15 | 21 | 16
*/

#include <stdio.h>
#define SZ_N 41

int N;
int BND[SZ_N]; // Bad Neighbors' Donation
int DT[SZ_N];

inline int
max(int a, int b) { return (a > b) ? a : b; }

static void
clear_buf()
{
	for (int i = 0; i < SZ_N; i++)
		BND[i] = DT[i] = 0;
}

static int
max_donations()
{
	int i, ans = 0;

	for (i = 0; i < N - 1; i++)
	{
		DT[i] = BND[i];
		
		if (i > 0)
			DT[i] = max(DT[i], DT[i - 1]);
		if (i > 1)
			DT[i] = max(DT[i], DT[i - 2] + BND[i]);
		
		ans = max(ans, DT[i]);
	}
	
	for (i = 0; i < N - 1; i++)
	{
		DT[i] = BND[i + 1];

		if (i > 0)
			DT[i] = max(DT[i], DT[i - 1]);
		if (i > 1)
			DT[i] = max(DT[i], DT[i - 2] + BND[i + 1]);

		ans = max(ans, DT[i]);
	}

	return ans;
}

int main()
{
	freopen("bad_neighbors.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &BND[i]);
		
		printf("%d\n", max_donations());

		clear_buf();
	}

	return 0;
}
