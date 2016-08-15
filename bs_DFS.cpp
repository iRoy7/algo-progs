#include <stdio.h>
#define SZN 51
/*
TREE:
5 4 // node 5, edge 4
1 2
2 3
2 4
3 5
      (1)
      /
    (2)
   /   \
 (3)   (4)
 /
(5)
*/

int G[SZN][SZN];
int visited[SZN];
int N, M;

/* Recursive implementation */
void recurr_DFS(int u)
{
	printf("%d ", u);
	visited[u] = 1;

	int v;
	for (v = 1; v <= N; v++)
	{
		if (!visited[v] && G[u][v])
		{
			visited[v] = 1;
			recurr_DFS(v);
		}
	}
}

/* Iterative stack-based implementation */
int top = -1;
int stack[SZN];
int V[SZN];

void init()
{
	top = -1;
	int i;
	for (i = 0; i < SZN; i++)
		stack[i] = V[i] = 0;
}

void iterr_DFS(int s)
{
	init();
	stack[++top] = s;

	while (top != (-1))
	{
		int x = stack[top--];
		
		if (V[x]) continue;
		
		V[x] = 1;
		
		// do something with x
		printf("%d ", x);

		int w;
		for (w = 1; w <= N; w++)
		{
			if (!V[w] && G[x][w])
				stack[++top] = w;
		}
	}
}

int main()
{
	freopen("dfs.txt", "r", stdin);
	
	scanf("%d %d", &N, &M);

	int i;

	for (i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = G[u][v] = 1;
	}

	recurr_DFS(1);
	printf("\n");

	iterr_DFS(1);
	printf("\n");

	return 0;
}
