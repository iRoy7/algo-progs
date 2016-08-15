/*
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

OUTPUT
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
// Iterative
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

		int w;
		for (w = 1; w <= N; w++)
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
// Recursive
void DFS(int u)
{
	// general case
	printf("%d ", u);
	visited[u] = 1;

	int v;
	for (v = 1; v <= N; v++)
	{
		if (!visited[v] && G[u][v])
		{
			visited[v] = 1;
			DFS(v);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	int i, j;
	for (i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}

    for (j = 0; j < N; j++)
    {
        visited[j] = 0;
    }
    
	printf("[DFS]: Recursive\n");
	DFS(1);
	printf("\n\n");

	printf("[BFS]: Iterative\n");
	BFS(1);
	printf("\n");

	return 0;
}
