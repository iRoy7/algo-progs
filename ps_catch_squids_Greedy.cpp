/*
INPUT:
7 10 6
2 2
2 4
6 2
7 4
3 3
5 6
=========
OUTPUT:
3
*/

#include <stdio.h>
#define SZ_M 110

int row[SZ_M];
int col[SZ_M];
int N, L, M, cnt;

inline int
max(int a, int b) { return (a > b) ? a : b; }

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_M; i++)
		row[i] = col[i] = 0;
}

static int
count_squids(int st_y, int st_x, int ed_y, int ed_x)
{
	int squid = 0;
	int i;

	for (i = 0; i < M; i++)
	{
		if ((row[i] >= st_y && row[i] <= ed_y)
			&& (col[i] >= st_x && col[i] <= ed_x))
			squid++;
	}

	return squid;
}

static int
throw_mesh(int sy, int sx)
{
	int squids = 0;
	int width;

	for (width = 1; width <= (L / 2) - 1; width++)
	{
		int height = (L / 2) - width;
		squids = max(squids, count_squids(sy, sx, sy + height, sx + width));
	}

	return squids;
}

static void
catch_squids()
{
	int i, j;

	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++)
			cnt = max(cnt, throw_mesh(row[i], col[j]));

}

int main()
{
	setbuf(stdout, NULL);
	
	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d%d%d", &N, &L, &M);

		for (i = 0; i < M; i++)
		{
			int y, x;
			scanf("%d%d", &y, &x);
			row[i] = y;
			col[i] = x;
		}

		// solve
		cnt = 0;
		/* catch squids */
		catch_squids();

		// output
		printf("%d\n", cnt);

		// clear
		clear_buf();
	}

	return 0;
}
