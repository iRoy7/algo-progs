// Maze maker from TOPCODER
// test cases:
/*
inputs:
6
3 3
...
...
...
0 1
4
1 0
0 1
- 1 0
0 - 1
3 3
...
...
...
0 1
8
1 0
0 1
- 1 0
0 - 1
1 1
1 - 1
- 1 1
- 1 - 1
4 3
X.X
...
XXX
X.X
0 1
4
1 0
0 1
- 1 0
0 - 1
6 7
.......
X.X.X..
XXX...X
....X..
X....X.
.......
5 0
8
1 0
0 1
- 1 0
0 - 1
1 1
1 - 1
- 1 1
- 1 - 1
1 7
.......
0 0
6
1 0
0 1
1 0
0 1
1 0
0 1
1 14
..X.X.X.X.X.X.
0 0
4
2 0
0 2
- 2 0
0 - 2
----------------
outputs:
3
2
-1
7
6
-1
*/

#include <stdio.h>
#define MAX_M 51
#define QR 2501

struct Point {
	int u, v; // u->y, v->x;
};

struct Queue {
	int head, tail;
	struct Point containers[QR];
	Queue() : head(0), tail(0) {}
	void init() { head = 0, tail = 0; }
	bool is_empty() { return head == tail; }
	void enqueue(struct Point x) { containers[tail++] = x; }
	struct Point dequeue() { return containers[head++]; }
	struct Point front() { return containers[head]; }
	int size() { return (tail - head); }
};

char MAP[MAX_M][MAX_M];
int board[MAX_M][MAX_M];
int mrow[MAX_M];
int mcol[MAX_M];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int H, W, M;
struct Point st;
struct Queue q;

inline bool
is_safe(int y, int x)
{
	return (y >= 0 && y < H && x >= 0 && x < W);
}

inline int 
max(int a, int b)
{
	return (a > b) ? a : b;
}

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < MAX_M; i++)
	{
		mrow[i] = mcol[i] = 0;
		for (j = 0; j < MAX_M; j++)
			MAP[i][j] = 0;
	}

	return;
}

static void
print_board()
{
	int i, j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	return;
}

static int
bfs()
{
	int i, j;
	int max_j = -2147483648;

	q.init();
	q.enqueue(st);

	while (!q.is_empty())
	{
		struct Point x = q.front();
		q.dequeue();
		
		for (i = 0; i < M; i++)
		{
			// next move
			int ny = x.u + mrow[i];
			int nx = x.v + mcol[i];

			if ((is_safe(ny, nx))
				&& board[ny][nx] == -1
				&& MAP[ny][nx] == '.')
			{
				board[ny][nx] = board[x.u][x.v] + 1;
				struct Point next;
				next.u = ny, next.v = nx;
				q.enqueue(next);
			}
		}
	}

	//print_board();
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (MAP[i][j] == '.'
				&& board[i][j] == -1)
				return -1;
			max_j = max(max_j, board[i][j]);
		}
	}

	return max_j;
}

int main()
{
	freopen("making_maze.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d", &H, &W);
		int i, j;
		for (i = 0; i < H; i++)
			scanf("%s", MAP[i]);
		// start point
		scanf("%d%d", &st.u, &st.v);
		// move count
		scanf("%d", &M);
		// moving info
		for (i = 0; i < M; i++)
			scanf("%d%d", &mrow[i], &mcol[i]);

		// initialize board with -1
		for (i = 0; i < H; i++)
			for (j = 0; j < W; j++)
				board[i][j] = -1;
		board[st.u][st.v] = 0;

		// solve
		int max_mv = 0;
		max_mv = bfs();
		// output
		printf("%d\n", max_mv);
		// clear buffer
		clear_buf();
	}
	return 0;
}
