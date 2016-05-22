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
exp_dfs(int vt)
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
	Queue() : head(0), tail(0) {}
	void init(){ head = 0, tail = 0; }
	bool is_empty() { return head == tail; }
	void enqueue(int x) { containers[tail++] = x; }
	int dequeue() { return containers[head++]; }
	int front() { return containers[head]; }
	int size() { return (tail - head); }
};

struct Queue q;

static void 
exp_bfs(int st)
{
	visited[st] = true;
	q.enqueue(st);

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

		// explorers via DFS
		exp_dfs(1);
		for (i = 1; i <= N; i++)
			visited[i] = false;

		// explorers via BFS
		exp_bfs(1);
		printf("\n");
		
		clear_buf();
	}

	return 0;
}
