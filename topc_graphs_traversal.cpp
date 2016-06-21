/* 
input:
2
11
0 1 1 0 0 0 0 0 0 0 0
1 0 0 1 0 0 0 0 0 0 0
1 0 0 0 1 1 1 0 0 0 0
0 1 0 0 0 0 0 1 1 0 0
0 0 1 0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 1
0 0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0
5
0 1 1 0 0 
1 0 0 1 0
1 0 0 0 1
0 1 0 0 0
0 0 1 0 0
=======================
output:
1 2 4 8 9 3 5 10 6 7 11
1 2 3 4 5 6 7 8 9 10 11
1 2 4 3 5
1 2 3 4 5
*/
#include <stdio.h>
#define SZ_G 21
#define QR 402

int N;
int G[SZ_G][SZ_G];
bool visited[SZ_G];

static void
clear_buf()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		visited[i] = false;
		for (j = 1; j <= N; j++)
			G[i][j] = 0;
	}

	return;
}

static void
print_grp() {
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	return;
}

static void 
traversal_DFS(int vt)
{
	if (vt == N)
	{
		printf("%d\n", vt);
		return;
	}

	visited[vt] = true;

	printf("%d ", vt);

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && G[vt][i] )
		{
			visited[i] = true;
			exp_dfs(i);
		}
	}

	return;
}

struct Queue {
	int head, tail;
	int containers[QR];
	Queue(void) : head(0), tail(0) {}
	void init(){ head = 0, tail = 0; }
	bool is_empty() { return head == tail; }
	void enqueue(int x) { containers[tail++] = x; }
	int dequeue() { return containers[head++]; }
	int front() { return containers[head]; }
	int size() { return (tail - head); }
};

struct Queue q;

static void 
traversal_BFS(int st)
{
	q.init();
	q.enqueue(st);
	visited[st] = true;

	while (!q.is_empty())
	{
		int x = q.front();
		printf("%d ", x);
		q.dequeue();
		
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i] && G[x][i])
			{
				visited[i] = true;
				q.enqueue(i);
			}
		}
	}

	return;
}

int main()
{
	freopen("graph_info.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, i, j;
	scanf("%d", &T);

	while (T--) {
		// input
		scanf("%d", &N);
		// adj-matrix
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
			{
				int x;
				scanf("%d", &x);
				if (x)
					G[i][j] = G[j][i] = x;
			}

		// Traversal via DFS
		traversal_DFS(1);
		for (i = 1; i <= N; i++)
			visited[i] = false;

		// explorers via BFS
		traversal_BFS(1);
		printf("\n");
		
		// clean buffer
		clear_buf();
	}

	return 0;
}
