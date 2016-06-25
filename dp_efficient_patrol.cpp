#include <stdio.h>
#define SZ_N 1001
// row->y, col->x
int row[SZ_N];
int col[SZ_N];

int N, evnts;
// Dynamic Table
/* minimum length from here to another: DT[heare][another] */
int DT[SZ_N][SZ_N];

inline int
min(int a, int b) { return (a > b) ? b : a; }
inline int 
ABS(int a) { return (a > 0) ? a : (-a); }

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_N; i++)
		row[i] = col[i] = 0;
	for (i = 0; i < SZ_N*SZ_N; i++)
		*((int *)DT + i) = -1;
}

static int
get_Dist(int a, int b)
{
	return ABS(row[a] - row[b]) + ABS(col[a] - col[b]);
}

static int
min_Dist(int here, int another)
{
	int &ret = DT[here][another];
	if (ret != -1) return ret;

	// base cases
	if (here == evnts) return 0;

	int next = here + 1;
	return ret = min(min_Dist(next, another) + get_Dist(here, next),
		min_Dist(next, here) + get_Dist(another, next));
}

static void
construct(int here, int another, int car)
{
	if (here == evnts) return;
	int next = here + 1;
	if (min_Dist(next, another) + get_Dist(here, next)
		< min_Dist(next, here) + get_Dist(another, next))
	{
		printf("%d\n", car);
		construct(next, another, car);
	}
	else
	{
		printf("%d\n", 3 - car);
		construct(next, here, 3 - car);
	}
}

int main()
{
	freopen("events_info_for_patroling.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, a, b;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &evnts);

		evnts++;
		row[0] = col[0] = 1; // 첫번째 사건
		row[1] = col[1] = N; // 두번째 사건
		// 실제 입력되는 사건 3번째라고 두고,
		for (i = 2; i <= evnts; i++)
			scanf("%d%d", &row[i], &col[i]);

		a = b = 0;
		a = min_Dist(2, 1) + get_Dist(0, 2);
		b = min_Dist(2, 0) + get_Dist(1, 2);

		printf("%d\n", min(a, b));

		if (a < b)
		{
			puts("1");
			construct(2, 1, 1);
		}
		else
		{
			puts("2");
			construct(2, 0, 2);
		}

		clear_buf();
	}

	return 0;
}
