// Get maze path depth
// BFS
#include <stdio.h>
#define MAX_M 51
#define QR 2501

struct Point {
	int u, v;
};

struct Queue {
	int head, tail;
	struct Point containers[QR];
	Queue() : head(0), tail(0) {}
	void init() { head = 0, tail = 0; }
	bool is_empty() { return head == tail; }
	void enqueue(Point x) { containers[tail++] = x; }
	struct Point dequeue() { return containers[head++]; }
	struct Point front() { return containers[head]; }
	int size() { return (tail - head); }
};

char MAP[MAX_M][MAX_M];
int DEP[MAX_M][MAX_M];
int visited[MAX_M][MAX_M];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int H, W;
struct Point st, end;
struct Queue q;

inline bool
is_safe(int y, int x)
{
	return (y >= 0 && y < H && x >= 0 && x < W);
}

static int 
bfs()
{
	// mark visited
	visited[st.u][st.v] = 1;

	q.init();
	q.enqueue(st);
	DEP[st.u][st.v] = 0; // depth of Maze

	while (!q.is_empty())
	{
		struct Point x = q.front();
		q.dequeue();
		if (x.u == end.u && x.v == end.v) break;

		for (int i = 0; i < 4; i++)
		{
			int ny = x.u + dy[i];
			int nx = x.v + dx[i];
			if ((is_safe(ny, nx)) 
				&& !visited[ny][nx]
				&& MAP[ny][nx] == '.')
			{
				DEP[ny][nx] = DEP[x.u][x.v] + 1;
				struct Point next;
				next.u = ny, next.v = nx;
				q.enqueue(next);
			}
		}
	}

	return DEP[end.u][end.v];
}

int main()
{
	freopen("maze_map.txt", "r", stdin);
	setbuf(stdout, NULL);

	int i, j;
	scanf("%d%d", &H, &W);
	for (i = 0; i < H; i++)
	{
		scanf("%s", MAP[i]);
		for (j = 0; j < W; j++)
		{
			if (MAP[i][j] == 'S')
				st.u = i, st.v = j;
			else if (MAP[i][j] == 'G')
				end.u = i, end.v = j, MAP[i][j] = '.';
		}
	}

	int depth = 0;
	depth = bfs();

	printf("%d\n", depth);
	
	return 0;
}
