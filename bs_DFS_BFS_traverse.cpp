/*
INPUT:
5 4
1 2
2 3
2 4
3 5
    (1)
    /
   (2)
   /  \
 (3)  (4)
 /
(5)

OUTPUT:
DFS
1->2->3->5->4
BFS
1->2->3->4->5
*/
#include <stdio.h>
#define SZN 51
#define QR 102

int G[SZN][SZN];
int V[SZN];
int visited[SZN];
int N, M;

////////////////////////////////
// Queue
int Q[QR];
int head, tail;
void init()
{
	head = -1, tail = -1;
	int i;
	for (i = 0; i < QR; i++)
		Q[i] = 0;
	for (i = 0; i < SZN; i++)
		V[i] = 0;
}
////////////////////////////////
// BFS: Iterative
void BFS(int s)
{
	init();

	Q[++tail] = s;
	V[s] = 1;

	while (tail != head)
	{
		int cur = Q[++head];

		/* do something with cur */
		printf("%d ", cur);

		if (cur == N)
		{
			printf("\n - Reach to the last node\n");
		}

		for (int w = 1; w <= N; w++)
		{
			if (!V[w] && G[cur][w])
			{
				Q[++tail] = w;
				V[w] = 1;
			}
		}
	}
}
////////////////////////////////
// DFS: Recursive
void DFS(int u)
{
	printf("%d ", u);
	visited[u] = 1;

	for (int v = 1; v <= N; v++)
	{
		if (visited[v] == 0
			&& G[u][v])
		{
			visited[v] = 1;
			DFS(v);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	int i;
	for (i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}

	for (i = 0; i < N; i++)
	{
		visited[i] = 0;
	}

	printf("[DFS]: Recursive\n");
	DFS(1);
	printf("\n\n");

	printf("[BFS]: Iterative\n");
	BFS(1);
	printf("\n");

	return 0;
}
