/*
INPUT:
3
15 4 2
0 0 0 1 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 3 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2 3
2 4
3 9
5 12
15 4 2
0 0 0 1 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 3 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2 3
2 4
3 9
5 12
15 4 2
0 0 0 1 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 3 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2 3
2 4
3 9
5 12
================================
OUTPUT:
2
2
1

*/


#include <stdio.h>
#define SZ_M 20
#define MAX_AP 5
#define MAX_IOT 10

struct AP {
	int cov;
	int iots[MAX_IOT];
};

int map[SZ_M][SZ_M];
int iot_map[SZ_M][SZ_M];
int N, M, R, iot_cnt;
struct AP aps[MAX_AP];
int used_aps[MAX_AP];
int covered[MAX_IOT];

inline int
ABS(int a) { return (a > 0) ? a : (-a); }


static bool
is_Done()
{
	int i;
	for (i = 1; i <= iot_cnt; i++)
		if (!covered[i])
			return false;
	return true;
}

static void
clear_Buf()
{
	int i, j;
	for (i = 0; i < SZ_M*SZ_M; i++)
	{
		*((int *)map + i) = 0;
		*((int *)iot_map + i) = 0;
	}
	for (i = 0; i < MAX_IOT; i++)
		covered[i] = 0;
	for (i = 0; i < MAX_AP; i++)
	{
		aps[i].cov = 0;
		used_aps[i] = 0;
		for (j = 0; j < MAX_IOT; j++)
			aps[i].iots[j] = 0;
	}
}

static void
print_Map()
{
	int i, j;
	for (i = 0; i < SZ_M; i++)
	{
		for (j = 0; j < SZ_M; j++)
		{
			printf("%d ", iot_map[i][j]);
		}
		printf("\n");
	}
}

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p;
	struct AP tmp;
	l = s - 1, r = e + 1, p = aps[(s + e) / 2].cov;
	while (1)
	{
		while (aps[++l].cov > p);
		while (aps[--r].cov < p);
		if (l >= r) break;
		tmp = aps[l], aps[l] = aps[r], aps[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static bool
safe(int y, int x)
{
	return (y >= 0 && y < N) && (x >= 0 && x < N);
}

static bool
possible_Dist(int y, int x, int ty, int tx, int r)
{
	return (ABS(y - ty) + ABS(x - tx)) <= r;
}

static void
make_iot_Map(int y, int x, int r, int n)
{
	//printf("before iot map:\n");
	//print_Map();
	int i, j;

	for (i = (-r); i <= r; i++)
	{
		for (j = (-r); j <= r; j++)
		{
			int ty = y + i;
			int tx = x + j;
			if (safe(ty, tx) && possible_Dist(y, x, ty, tx, r))
			{
				if (iot_map[ty][tx])
				{
					int x = iot_map[ty][tx] * 10;
					iot_map[ty][tx] = x + n;
				}
				else
					iot_map[ty][tx] = n;
			}
		}
	}
	//printf("current iot map:\n");
	//print_Map();
}

static void
put_APs(int y, int x, int r, int n)
{
	int i, j;

	for (i = (-r); i <= r; i++)
	{
		for (j = (-r); j <= r; j++)
		{
			int ty = y + i;
			int tx = x + j;
			if (safe(ty, tx) && possible_Dist(y, x, ty, tx, r))
			{
				int x = iot_map[ty][tx];
				if (x >= 11)
				{
					while (x > 0)
					{
						int k = x % 10;
						/* do something with k */
						if (!aps[n].iots[k])
						{
							aps[n].iots[k]++;
							aps[n].cov++;
						}
						x /= 10;
					}
				}
				else if (x >= 1 && x < 10)
				{
					if (!aps[n].iots[x])
					{
						aps[n].iots[x]++;
						aps[n].cov++;
					}
				}
			}
		}
	}
}

int main()
{
	freopen("iots_map_info.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d%d%d", &N, &M, &R);
		/* map and iot map initialized */
		int iot_n = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				int iot_r;
				scanf("%d", &iot_r);
				map[i][j] = iot_r;
				if (iot_r)
				{
					iot_n++;
					make_iot_Map(i, j, iot_r, iot_n);
				}
			}
		}

		// solve
		/* put APs */
		for (i = 0; i < M; i++)
		{
			int y, x;
			scanf("%d%d", &y, &x);
			put_APs(y, x, R, i);
			//printf("%d th AP covers %d IoTs\n", i, aps[i].cov);
		}

		/* sort APs by cover size */
		qsort(0, M - 1);

		/* count APs to cover all IoTs */
		bool all_covered = false;
		iot_cnt = iot_n;

		for (i = 0; i < M; i++)
		{
			if (aps[i].cov > 0)
			{
				for (j = 1; j <= iot_cnt; j++)
				{
					if (aps[i].iots[j])
					{
						if (!covered[j])
						{
							//printf("Cover %d iotivity device\n", j);
							covered[j]++;
							used_aps[i]++;
						}						
					}
				}
			}
			
			if (is_Done())
			{
				//printf("All covered...Done()!!\n");
				all_covered = true;
				break;
			}
		}

		// output
		if (all_covered)
		{
			/* count used APs */
			int used_ap_cnt = 0;
			for (i = 0; i < M; i++)
				if (used_aps[i])
					used_ap_cnt++;

			printf("%d\n", used_ap_cnt);
		}
		else
			printf("-1\n");

		// clear buf
		clear_Buf();
	}

	return 0;
}
