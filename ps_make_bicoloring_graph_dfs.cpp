/*
input:
2
8 7
1 2
1 3
1 4
2 5 
2 6
3 7
4 8
8 8
1 2
1 3
1 4
2 5 
2 6
3 7
4 8
5 6
-------------------
output:
OK
IMPOSSIBLE
*/

#include <stdio.h>
#define SZ_N 51

int g[SZ_N][SZ_N];
int visited[SZ_N];
int N, M;
int colorable;

static void
dfs(int vtx, int color)
{
	// base cases ... exit condition for backtracking
	if (vtx == N)
		return;

	visited[vtx] = color;

	int i;

	for (i = 1; i <= N && colorable; i++)
	{
		if (g[vtx][i] == 0)
			continue;

		if (visited[i] == 0)
		{
			dfs(i, color % 2 + 1); // 색을 2, 1 반복
		}
		else
		{
			if (visited[i] == color)
			{
				colorable = 0;
				return;
			}
		}
	}
}

int main()
{
	freopen("graph_info_for_bicoloring.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d%d", &N, &M);
		for (i = 0; i < M; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			// un-directed graph
			g[u][v] = g[v][u] = 1;
		}

		// solve
		/* painting: bicoloring */
		colorable = 1;
		dfs(1, 1); // vtx, color

		// output
		if (colorable == 0)
			printf("IMPOSSIBLE\n");
		else
			printf("OK - bicoloring graph\n");

		// clear buffer
		for (i = 0; i < N; i++)
			visited[i] = 0;
		for (i = 0; i < N*N; i++)
			*((int *)g + i) = 0;
	}

	return 0;
}
