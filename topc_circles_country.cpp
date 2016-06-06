/* 
input:
4
1
0 0 2
-5 1 5 1
3
0 0 2
-6 1 2
6 2 2
-5 1 5 1
7
1 1 8
-3 -1 1
2 2 2
5 5 1
-4 5 1
12 1 1
12 1 2
-5 1 12 1
8
-3 -1 1
2 2 3
2 3 1
0 1 7
-4 5 1
12 1 1
12 1 2
12 1 3
2 3 13 2
======================
outputs:
0 | 2 | 3 | 5
*/
#include <stdio.h>
#define SZ_C 51

int N;
int X[SZ_C], Y[SZ_C], R[SZ_C];
int x1, y1, x2, y2;

static void
clear_buf()
{
	for (int i = 0; i < SZ_C; i++)
		X[i] = Y[i] = R[i] = 0;
}

// 원의 중심과의 거리가 반경보다 작다면 원의 내부에 있을 것임
static bool
inside(int cx, int cy, int px, int py, int r)
{
	return (cx - px)*(cx - px) + (cy - py)*(cy - py) <= r*r;
}

static int
least_borders()
{
	int i, num = 0;
	for (i = 0; i < N; i++)
	{
		if (inside(X[i], Y[i], x1, y1, R[i])
			!= inside(X[i], Y[i], x2, y2, R[i]))
			num++;
	}

	return num;
}

int main()
{
	freopen("circles_country.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d%d%d", &X[i], &Y[i], &R[i]);
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		printf("%d\n", least_borders());

		clear_buf();
	}

	return 0;
}
