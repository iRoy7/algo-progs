/* 
input:
1
7
0 1 0 0 1 0 1
0 1 0 0 1 0 1
0 1 1 0 1 1 1
0 0 1 0 0 0 0
0 0 1 0 0 1 1
0 0 0 0 0 1 1
0 0 1 1 1 1 1
--------------------
output:
3
9|7|6
*/


#include <stdio.h>
#define SZ_N 31
#define QR 101

struct Point {
	int u, v; // u->y, v->x
};

struct Queue {
	int head, tail;
	struct Point containers[QR];
	Queue(void) : head(0), tail(0) {}
	void init() { head = tail = 0; }
	bool is_Empty() { return head == tail; }
	void enqueue(struct Point x) { containers[tail++] = x; }
	struct Point dequeue() { return containers[head++]; }
	struct Point front() { return containers[head]; }
};

int N;
int map[SZ_N][SZ_N];
int size[SZ_N*SZ_N];
struct Queue q;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

static bool
safe(int y, int x)
{
	return (0 <= y && y < N) && (0 <= x && x < N);
}

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < N + 1; i++)
		for (j = 0; j < N + 1; j++)
			map[i][j] = 0;
	for (i = 0; i < N*N + 1; i++)
		size[i] = 0;
}

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = size[(s + e) / 2];
	while (1)
	{
		while (size[++l] > p);
		while (size[--r] < p);
		if (l >= r) break;
		tmp = size[l], size[l] = size[r], size[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

/* a: y, b: x, c: color*/
static void
bfs(int a, int b, int c)
{
	q.init();
	/* visiting -> paintng th point with 'c' color */
	map[a][b] = c;

	struct Point st;
	st.u = a, st.v = b;
	q.enqueue(st);

	while (!q.is_Empty())
	{
		struct Point p = q.front();
		/* check x and do something */
		q.dequeue();
		/* traversal to 4 directions */
		int i;
		for (i = 0; i < 4; i++)
		{
			int y = p.u + dy[i];
			int x = p.v + dx[i];
			if (safe(y, x) && map[y][x] == 1)
			{
				map[y][x] = c;
				struct Point nx;
				nx.u = y, nx.v = x;
				q.enqueue(nx);
			}
		}
	}
}

int main()
{
	freopen("mole_tunnels_map.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j, cnt;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				scanf("%d", &map[i][j]);

		// solve
		/* find tunnels */
		cnt = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (map[i][j] == 1)
				{
					/* cnt <- color */
					cnt++;
					bfs(i, j, cnt + 1);
				}
			}
		}
		/* count tunnels-> tunnels length */
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (map[i][j])
					size[map[i][j] - 2]++;
		/* sorting */
		qsort(0, cnt - 1);

		// output
		printf("cnt = %d\n", cnt);
		for (i = 0; i < cnt; i++)
			printf("%d\n", size[i]);

		// clear buffer
		clear_buf();
	}

	return 0;
}
