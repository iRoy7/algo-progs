/*
input:
2
7 10
1 2 1
1 4 5
1 6 10
2 3 4
2 4 4
3 5 6
4 5 5
4 6 4
5 7 5
6 7 7
7 10
1 2 1
1 4 5
1 6 10
2 3 4
2 4 3
3 5 6
4 5 5
4 6 4
5 7 5
6 7 7
------------
output:
15 | 14
*/

#include <stdio.h>
#define SZ_N 101

int N, M; // N: vertex, M: edge
int min_exp;
int map[SZ_N][SZ_N];
bool visited[SZ_N];

static void
dfs(int vtx, int exp)
{
	// bases...exit condition for backtracking
	if (vtx == N)
	{
		printf("D1: exp = %d\n", exp);
		if (exp < min_exp)
			min_exp = exp;
		return;
	}
	
	int i;
	// traversal
	for (i = 1; i <= N; i++)
	{
		if (!visited[i] && map[vtx][i])
		{
			visited[i] = true; // mark
			dfs(i, exp + map[vtx][i]);
			visited[i] = false; // un-mark
		}
	}
}

int main()
{
	freopen("travel_expenses_info.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d%d", &N, &M);
		for (i = 0; i < M; i++)
		{
			int u, v, exp;
			scanf("%d%d%d", &u, &v, &exp);
			// directed graph
			map[u][v] = exp;
		}

		// solve
		/* get least expenses */
		/* start from 1 vertex(node) */
		min_exp = 2147483647;
		dfs(1, 0);

		// output
		printf("%d\n", min_exp);

		// clear buffer
		for (i = 0; i < N; i++)
			visited[i] = false;
		for (i = 0; i < N*N; i++)
			*((int *)map + i) = 0;
	}

	return 0;
}
