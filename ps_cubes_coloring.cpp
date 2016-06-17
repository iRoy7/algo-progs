#include <stdio.h>
#define SZ_C 1000001

int y_aspt[SZ_C];
int x_aspt[SZ_C];
int z_aspt[SZ_C];
long long yx_aspt[SZ_C];
long long yxz_aspt[SZ_C];

// cube's color i = |x-A| + |y-B| + |z-C| = i(mod)N
int N; // N->color
int x, y, z, A, B, C;

inline int
ABS(int a) { return (a > 0) ? a : (-a); }

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_C; i++)
		y_aspt[i] = x_aspt[i] = z_aspt[i] = yx_aspt[i] = yxz_aspt[i] = 0;
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i, j;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d%d %d%d%d %d", &x, &y, &z, &A, &B, &C, &N);

		for (i = 0; i < y; i++)
			y_aspt[ABS(i - B) % N]++;
		for (i = 0; i < x; i++)
			x_aspt[ABS(i - A) % N]++;
		for (i = 0; i < z; i++)
			z_aspt[ABS(i - C) % N]++;

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				yx_aspt[(i + j) % N] += y_aspt[i] * x_aspt[j];

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				yxz_aspt[(i + j) % N] += yx_aspt[i] * z_aspt[j];

		for (i = 0; i < N; i++)
			printf("%lld ", yxz_aspt[i]);
		printf("\n");

		clear_buf();
	}

	return 0;
}
