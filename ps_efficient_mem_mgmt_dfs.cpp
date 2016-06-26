/*
input:
1
7 60
30 40 10 50 2 3 7
30 50 80 10 70 60 7
----------------------------
output:
40 <- minimum cost to get memory to be seized
*/

#include <stdio.h>
#define SZ_N 501

int N, M;
int mem[SZ_N];
int cost[SZ_N];
int col[SZ_N];
int min_cost;

static void
clear_buf()
{
	int i;

	for (i = 0; i < SZ_N; i++)
		mem[i] = cost[i] = col[i] = 0;
}

// aid: app id
// sm: seized memory
// sc: sum of cost
static void
dfs(int aid, int sm, int sc)
{
	// base cases ... exit condition for backtracking
	if (aid == N) return;
	if (sm >= M)
	{
		if (sc < min_cost)
			min_cost = sc;
		return;
	}

	int i;

	for (i = aid; i < N; i++)
	{
		if (!col[i])
		{
			col[i] = 1; // select marked!!!
			dfs(i + 1, sm + mem[i], sc + cost[i]);
			col[i] = 0; // un-marked!!!
		}
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
			scanf("%d", &mem[i]);
		for (i = 0; i < N; i++)
			scanf("%d", &cost[i]);

		// solve
		/* find minimum cost to get Memory to be seized */
		/* app id, seized mem, sum cost */
		min_cost = 2147483647;
		dfs(0, 0, 0);

		// output
		printf("%d\n", min_cost);

		// clear buffer
		clear_buf();
	}

	return 0;
}
