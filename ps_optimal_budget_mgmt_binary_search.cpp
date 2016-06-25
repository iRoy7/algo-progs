/*
input:
1
6 270
50 30 45 60 70 25
--------------------
output:
60
*/

#include <stdio.h>
#define SZ_A 101

int N, M;
int act[SZ_A];
int max_spt;

static void
qsort(int s, int e)
{
	if (s >= e) return;
	
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = act[(s + e) / 2];
	while (1)
	{
		while (act[++l] < p);
		while (act[--r] > p);
		if (l >= r) break;
		tmp = act[l], act[l] = act[r], act[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static void
estimate_Budgets(int l, int r)
{
	// base cases
	if (r*N <= M)
	{
		max_spt = r;
		return;
	}

	while (l <= r)
	{
		int i;
		int mid = (l + r) / 2;
		int sum = 0;

		for (i = 0; i < N; i++)
		{
			if (act[i] < mid)
				sum += act[i];
			else
				sum += mid;
		}

		if (sum <= M)
		{
			if (max_spt < mid)
				max_spt = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; i++)
			scanf("%d", &act[i]);

		// solve
		/* qsort */
		qsort(0, N - 1);
		/* get tne maximum baseline */
		estimate_Budgets(0, act[N - 1]);

		// output
		printf("%d\n", max_spt);

		// clear buffer
		for (i = 0; i < N; i++)
			act[i] = 0;
	}

	return 0;
}
