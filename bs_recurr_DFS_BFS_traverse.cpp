/*
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
int N, M;
////////////////////////////////
// Queue
int q[QR];
int head, tail;
void q_init() 
{ 
	head = -1, tail = -1; 
	int i;
	for (i = 0; i < QR; i++) q[i] = 0;
}
////////////////////////////////
void Clean()
{
	int i;

	for (i = 0; i < (SZN*SZN); i++)
	{
		*((int *)G + i) = 0;
	}
}

void BFS(int n)
{
	q_init();

	V[n] = 1;
	q[++tail] = n;

	while (tail != head)
	{
		int x = q[++head];

		printf("%d ", x);

		/* do something with x */
		int i;
		for (i = 1; i <= N; i++)
		{
			if (!V[i] && G[x][i])
			{
				V[i] = 1;
				q[++tail] = i;
			}
		}
	}
}

void DFS(int n)
{
	// base case
	if (n == N)
	{
		printf("%d ", n);
		return;
	}

	// general case
	printf("%d ", n);
	V[n] = 1;

	int i;

	for (i = 1; i <= N; i++)
	{
		if (!V[i] && G[n][i])
		{
			V[i] = 1;
			DFS(i);
		}
	}
}

int main()
{
	freopen("graph_info.txt", "r", stdin); 
	setbuf(stdout, NULL);

	scanf("%d %d", &N, &M);

	int i, j;
	
	for (i = 0; i < M; i++)
	{
		V[i] = 0;
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}

	DFS(1);
	printf("\n");

	//BFS(1);
	//printf("\n");

	Clean();

	return 0;
}
