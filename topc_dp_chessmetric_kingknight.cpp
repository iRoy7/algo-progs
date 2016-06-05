/*
5
3
0 0 1 0 1
3
0 0 1 2 1
3
1 1 2 2 1
3
0 0 0 0 2
100
0 0 0 99 50
ouputs:
1 1 1 5 243097320072600
*/

#include <stdio.h>
#define SZ_CM 101
#define SZ_M 51

int size, sy, sx, ey, ex, num_m;
long long ways[SZ_CM][SZ_CM][SZ_M] = { 0 };

int dy[] = { 1, 0, -1, -1, -1, 0, 1, 1, -1, -2, -2, -1, 1, 2, 2, 1 };
int dx[] = { 1, 1, 1, 0, -1, -1, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2 };

static void
clear_buf()
{
	int i, j, k;
	for (i = 0; i < SZ_CM; i++)
		for (j = 0; j < SZ_CM; j++)
			for (k = 0; k < SZ_M; k++)
				ways[i][j][k] = 0;
}

static long long
howmany()
{
	int x, y, i, j;
	ways[sy][sx][0] = 1;

	for (i = 1; i <= num_m; i++)
	{
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < size; y++)
			{
				for (j = 0; j < 16; j++)
				{
					int nx = x + dx[j];
					int ny = y + dy[j];

					if (nx < 0 || ny < 0 || nx >= size || ny >= size)
						continue;
					ways[ny][nx][i] += ways[y][x][i - 1];
				}
			}
		}
	}

	return ways[ey][ex][num_m];
}

int main()
{
	freopen("chessmetric.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &size);
		scanf("%d%d %d%d %d", &sx, &sy, &ex, &ey, &num_m);
		printf("%lld\n", howmany());
		clear_buf();
	}

	return 0;
}
