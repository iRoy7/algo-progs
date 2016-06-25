/*
input:
2
9 8
0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0
0 1 1 1 1 1 1 0
0 1 1 0 0 1 1 0
0 1 1 1 1 1 1 0
0 1 1 0 0 1 1 0
0 1 1 1 1 1 1 0
0 0 1 1 1 1 0 0
0 0 0 0 0 0 0 0
7 8
0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0
0 1 0 0 0 0 1 0
0 1 1 1 1 1 1 0
0 1 0 0 0 0 1 0
0 0 1 1 1 1 1 0
0 0 0 0 0 0 0 0
---------------------
output:
4 | 2
*/

#include <stdio.h>
#define SZ_C 101

int N, M;
int cz[SZ_C][SZ_C];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

static bool
inside(int y, int x)
{
	return (0 <= y && y < N) && (0 <= x && x < M);
}

static bool
done()
{
	int i, j, cnt = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (cz[i][j] == -1 || cz[i][j] > 2)
				cz[i][j] = 0;
			else if (cz[i][j] == 2 || cz[i][j] == 1)
				cz[i][j] = 1, cnt++;
		}
	}

	return cnt == 0;	
}

static void
melting(int y, int x)
{
	cz[y][x] = -1;

	int i;

	for (i = 0; i < 4; i++)
	{
		int nx_y = y + dy[i];
		int nx_x = x + dx[i];

		if (inside(nx_y, nx_x))
		{
			if (cz[nx_y][nx_x] == 0)
				melting(nx_y, nx_x);
			else if (cz[nx_y][nx_x] > 0)
				cz[nx_y][nx_x]++;
		}
	}
}

int main()
{
	freopen("melting_cheeze.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j, spt;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf("%d", &cz[i][j]);

		// solve
		/* measure a time until melting a cheeze */
		for (spt = 0; !done(); spt++)
			melting(0, 0);

		// output
		printf("%d\n", spt);

		// clear buffer
		for (i = 0; i < N*M; i++)
			*((int *)cz + i) = 0;
	}

	return 0;
}
