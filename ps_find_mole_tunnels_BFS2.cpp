#include <stdio.h>
#define SZN 31
#define QR 990

int N;
int M[SZN][SZN];
int S[SZN*SZN];
/////////////////////////////
int head = -1, tail = -1;
struct Point { int y, x; };
struct Point Q[QR];
void init()
{
	head = -1, tail = -1;
	for (int i = 0; i < QR; i++)
		Q[i].y = Q[i].x = 0;
}

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool isWall(int y, int x)
{
	return (y < 0 || y >= N || x < 0 || x >= N);
}

void bfs(int sy, int sx, int c)
{
	init();
	struct Point st;
	st.y = sy, st.x = sx;
	Q[++tail] = st;
	M[sy][sx] = c;

	while (tail != head)
	{
		struct Point cur = Q[++head];
		/* do something with curr */

		int i;
		for (i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (!isWall(ny, nx)
				&& M[ny][nx] == 1)
			{
				struct Point next;
				next.y = ny, next.x = nx;
				Q[++tail] = next;
				M[ny][nx] = c;
			}
		}
	}
}

void print_M()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
}

void isort(int nSize)
{
	int i, j, tmp;
	for (i = 1; i < nSize; i++)
	{
		tmp = S[i];
		for (j = i - 1; j >= 0 && S[j] < tmp; j--)
			S[j + 1] = S[j];
		S[j + 1] = tmp;
	}
}

int main()
{
	freopen("find_modle_tunnels_BFS.txt", "r", stdin);

	int T, tc, i, j;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				scanf("%d", &M[i][j]);
		}

		int cnt = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (M[i][j] == 1)
				{
					cnt++;
					bfs(i, j, cnt + 1);
				}
			}
		}
		
		//print_M();

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (M[i][j])
				{
					S[M[i][j] - 2]++;
				}
			}
		}
		
		isort(cnt);

		printf("cnt = (%d)\n", cnt);
		for (i = 0; i < cnt; i++)
			printf("%d ", S[i]);
		printf("\n");

		/* Clean M/S */
	}

	return 0;
}
