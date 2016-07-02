#include <stdio.h>
#define SZ_MAP 55 // Map
#define SZ_H 11 // Houses

// N: row , M: col
int h_y[SZ_H], h_x[SZ_H];
int row[SZ_MAP], col[SZ_MAP];
int icr[SZ_MAP], dcr[SZ_MAP];
int N, M, H, ans;

inline int
min(int a, int b) { return (a > b) ? b : a; }
inline int 
max(int a, int b) { return (a > b) ? a : b; }
inline int 
ABS(int a) { return (a > 0) ? a : (-a); }

static void
clear_buf()
{
	int i;

	for (i = 0; i < SZ_H; i++)
		h_y[i] = h_x[i] = 0;
	for (i = 0; i < SZ_MAP; i++)
		row[i] = col[i] = 0;
	for (i = 0; i < SZ_MAP + SZ_MAP; i++)
		icr[i] = dcr[i] = 0;
}

static int
distance(int mode, int idx, int y, int x)
{
	int err = 0;
	// modes: 1:horizontal, 2:vertical, 3:incremental, 4:decremental
	// 1: check (+/-)y position only
	if (mode == 1)
	{
		return ABS(y - idx);
	}
	// 2: check (+/-)x position only
	else if (mode == 2)
	{
		return ABS(x - idx);
	}
	// 3: check (+/-)y, (+/-)x positions
	else if (mode == 3)
	{
		return ABS((y + x) - idx);
	}
	// 4: check (+/-)y, (+/-)x positions
	else if (mode == 4)
	{
		return ABS(((y - x) + (M - 1)) - idx);
	}
	else
		printf("WRN: WRONG MODE! mode = %d\n", mode);

	return err;
}

static int
get_max_dist(int mode, int idx)
{
	int i, d = -2147483648;
	// H: house cnt
	for (i = 0; i < H; i++)
	{
		int y = h_y[i], x = h_x[i];
		/* calculate a distance from house to streetlamp */
		d = max(d, distance(mode, idx, y, x));
	}
	
	return d;
}

static int
cons_streetlamps_hv()
{
	int i, dist = 2147483647;
	// N -> rows, M -> cols
	// horizontal
	for (i = 0; i < N; i++)
	{
		if (!row[i])
		{
			printf("D1: %d st row\n", i);
			/* get max distances from each houses */
			/* hotizontal mode : 1 */
			int d = get_max_dist(1, i);
			printf("--> max d from houses = %d\n", d);
			dist = min(dist, d);
			// dist = min(dist, get_max_dist(1, i);
		}
	}
	printf("=================================================\n");
	// vertical
	for (i = 0; i < M; i++)
	{
		if (!col[i])
		{
			printf("D2: %d st col\n", i);
			/* get max distances from each houses */
			/* vertical mode : 2 */
			int d = get_max_dist(1, i);
			printf("--> max d from houses = %d\n", d);
			dist = min(dist, d);
			// dist = min(dist, get_max_dist(2, i);
		}
	}
	printf("=================================================\n");

	return dist;
}

static int
cons_streetlamps_diagonal()
{
	int i, dist = 2147483647;
	// N -> rows, M -> cols
	// incremental diagonals
	for (i = 0; i < (N - 1) + (M - 1); i++)
	{
		if (!icr[i])
		{
			printf("D3: %d st icr\n", i);
			int d = get_max_dist(3, i);
			printf("--> max d from houses = %d\n", d);
			dist = min(dist, d);
			// dist = min(dist, get_max_dist(3, i);
		}
	}
	printf("=================================================\n");
	// decremental diagonals
	for (i = 0; i < (N - 1) + (M - 1); i++)
	{
		if (!dcr[i])
		{
			printf("D4: %d st dcr\n", i);
			int d = get_max_dist(4, i);
			printf("--> max d from houses = %d\n", d);
			dist = min(dist, d);
			// dist = min(dist, get_max_dist(4, i);
		}
	}
	printf("=================================================\n");

	return dist;
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input:
		scanf("%d%d%d", &N, &M, &H);

		for (i = 0; i < H; i++)
		{
			int y, x;
			scanf("%d%d", &y, &x);
			h_y[i] = y - 1, h_x[i] = x - 1;
			row[y - 1]++, col[x - 1]++;
			icr[(y - 1) + (x - 1)]++;
			dcr[(y - 1) - (x - 1) + (M - 1)]++;
		}

		// solve:
		ans = 2147483647;
		/* construct streetlamps on horizontal/vertical */
		ans = min(ans, cons_streetlamps_hv());
		/* construct streetlamps on increased/decreased diagonals */
		ans = min(ans, cons_streetlamps_diagonal());

		// output:
		printf("%d\n", ans);

		// clear
		clear_buf();
	}

	return 0;
}

