// Graph traversal
// Hamilton path
// inputs:
/*
2
4 4
1 2
1 3
2 4
3 4
5 7
1 2
1 3
1 5
2 4
2 5
3 5
4 5
-----------------------
outputs:
1 2 4 3 1
1 3 4 2 1
Path cnt = 2
1 2 4 5 3 1 
1 3 5 4 2 1
Path cnt = 2
*/
#include <stdio.h>
#define SZ_N 1001

int graph[SZ_N][SZ_N];
int path[SZ_N];

int N, M, cnt;

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_N; i++)
		path[i] = 0;
	
	for (i = 0; i < SZ_N*SZ_N; i++)
		*((int *)graph + i) = 0;
}

static int
bound(int vtx)
{
	int i;

	// base cases
	if (vtx == N - 1 && !graph[path[vtx] - 1][path[0] - 1])
		return 0;

	if (!graph[path[vtx - 1] - 1][path[vtx] - 1])
		return 0;

	for (i = vtx - 1; i >= 0; i--)
		if (path[vtx] == path[i])
			return 0;
	return 1;
}

static void
hamilton(int vt)
{
	int i, k;
	// visited all N number of vertexs   
	if (vt == N)
	{
		cnt++;

		for (k = 0; k < vt; k++)
			printf(" %d ", path[k]);
		printf(" %d\n", path[0]);
	}
	else
	{
		for (i = 2; i <= N; i++)
		{
			path[vt] = i;
			// check next vertex's valication
			if (bound(vt))
				hamilton(vt + 1);
		}
	}
}

int main()
{
	freopen("hamilton_graph_info.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d%d", &N, &M); 
		for (i = 0; i < M; i++)
		{
			// v->vertex, m-> edge
			int u, v;
			scanf("%d%d", &u, &v);
			graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1;
		}

		// solve
		cnt = 0;
		path[0] = 1;
		hamilton(1);

		// output
		printf("Path cnt = %d\n", cnt);

		// clear buf:
		clear_buf();
	}

	return 0;
}
