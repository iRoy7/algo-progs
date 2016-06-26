/*
Basically DFS traversal.
for performance, apply Greedy algorithm.
input:
6
6
6 4 4 4 6 9
3
2 10 1
9
1 1 1 4 6 1 1 1 1
7
20 1 4 76 30 68 5
10
78 15 74 82 78 85 3 40 44 53
11
94 12 18 38 79 21 38 42 56 93 94
=========================================
output:
12 12 9
10 2 1
6 6 5
76 68 60
192 181 179
199 194 192
*/

#include <stdio.h>
#define SZ_N 21
#define INT_MAX 0x7fffffff

int N;
int gifts[SZ_N];
int S, A, B, C;
int min_diff;

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = gifts[(s + e) / 2];
	while (1)
	{
		while (gifts[++l] < p);
		while (gifts[--r] > p);
		if (l >= r) break;
		tmp = gifts[l], gifts[l] = gifts[r], gifts[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static void
dfs(int id, int a, int b, int c)
{
	// Base cases ... 
	// Greedy!!!
	if (c > S / 3 || b > S / 2) return;
	int rest = S - (a + b + c);
	if (a + rest < b || b + rest < c) return;
	if (a - (c + rest) > INT_MAX) return;

	// Exit condition for backtracking
	if (id == N)
	{
		if (a >= b && b >= c)
		{
			int diff = a - c;
			if (diff == min_diff)
			{
				if (A > a)
					A = a, B = b, C = c;
			}
			else if (diff < min_diff)
			{
				min_diff = diff;
				A = a, B = b, C = c;
			}
		}

		return;
	}

	// Do main processing
	if (id < N)
	{
		// give a gift to 3rd
		dfs(id + 1, a, b, c + gifts[id]);
		// give a gift to 2nd
		dfs(id + 1, a, b + gifts[id], c);
		// give a gift to 1st
		dfs(id + 1, a + gifts[id], b, c);
	}

	return;
}

int main()
{
	freopen("gifts_info.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d", &N);

		// S: total weights
		S = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &gifts[i]);
			S += gifts[i];
		}

		// solve
		/* qsort first */
		qsort(0, N - 1);

		/* divide gifts to 3 persons */
		/* i th item, 1th someone, 2nd someone, 3rd someone */
		min_diff = INT_MAX;
		dfs(0, 0, 0, 0);

		// output
		printf("%d %d %d\n", A, B, C);

		// clear buf
		for (i = 0; i < N; i++)
			gifts[i] = 0;
	}

	return 0;
}
