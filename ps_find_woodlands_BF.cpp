/*
Brute-Force(Exhaustive) Search 
*/
#include <stdio.h>
#define MAX_N 101
#define MAX_WL 21

int N;
int land[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

struct WoodLand {
	int h, w, size;
};
struct WoodLand wl[MAX_WL];
int cnt;

static void
clear_buf()
{
	int i;
	for (i = 0; i < MAX_N*MAX_N; i++)
	{
		*((int *)land + i) = 0;
		*((int *)visited + i) = 0;
	}
	for (i = 0; i < MAX_WL; i++)
		wl[i].h = wl[i].w = wl[i].size = 0;
}

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p;
	struct WoodLand tmp;
	l = s - 1, r = e + 1, p = wl[(s + e) / 2].size;
	while (1)
	{
		while (wl[++l].size < p);
		while (wl[--r].size > p);
		if (l >= r) break;
		tmp = wl[l], wl[l] = wl[r], wl[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static void
find_woodlands(int y, int x)
{
	int i, j, row, col;
	row = col = 0;

	// check height via row
	for (i = y; i <= N; i++)
	{
		if (!land[i][x]) break;
		row++;
	}

	// check width vis col
	for (j = x; j <= N; j++)
	{
		if (!land[y][j]) break;
		col++;
	}

	// save woodland info.
	cnt++;
	wl[cnt].h = row;
	wl[cnt].w = col;
	wl[cnt].size = row*col;

	// mark founded woodland as visited
	for (i = y; i <= y + row - 1; i++)
		for (j = x; j <= x + col - 1; j++)
			visited[i][j] = 1;
}

int main()
{
	freopen("land_info.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// inputs
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				scanf("%d", &land[i][j]);

		// solve
		/* find woodlands */
		cnt = 0;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (!land[i][j]) continue;
				if (visited[i][j]) continue;
				find_woodlands(i, j);
			}
		}

		/* sorting based on size */
		qsort(1, cnt);
		/* height has a priority in case of same size */
		for (i = 2; i <= cnt; i++)
		{
			if (wl[i - 1].size == wl[i].size)
			{
				if (wl[i - 1].h > wl[i].h)
				{
					struct WoodLand tmp;
					tmp = wl[i], wl[i] = wl[i - 1], wl[i - 1] = tmp;
				}
			}
		}

		// output
		printf("%d\n", cnt);
		for (i = 1; i <= cnt; i++)
			printf(" %d %d\n", wl[i].h, wl[i].w);
		printf("-------------------\n");

		// clear buf
		clear_buf();
	}

	return 0;
}
