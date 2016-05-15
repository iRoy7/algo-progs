#include <stdio.h>
#define CMAX 1000000
long long int y_aspt[CMAX + 1];
long long int x_aspt[CMAX + 1];
long long int z_aspt[CMAX + 1];
long long int yx_aspt[CMAX + 1];
long long int yxz_aspt[CMAX + 1];
int T, N;
int x, y, z, a, b, c;
inline int abs(int a) { return (a > 0) ? a : (-a); }
inline void memory_clear() {
	for (int i = 0; i < CMAX + 1; i++)
		y_aspt[i] = x_aspt[i] = z_aspt[i] = yx_aspt[i] = yxz_aspt[i] = 0;
}
int main()
{
	int i, j;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	while (T--) {
		// inputs:
		scanf("%d%d%d %d%d%d %d", &x, &y, &z, &a, &b, &c, &N);
		memory_clear();
		// solve: 1. y, x, z aspects
		for (i = 0; i < y; i++)
			y_aspt[abs(i - b) % N]++;
		for (i = 0; i < x; i++)
			x_aspt[abs(i - a) % N]++;
		for (i = 0; i < z; i++)
			z_aspt[abs(i - c) % N]++;
		// solve: 2. y*x aspect
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				yx_aspt[(i + j) % N] += y_aspt[i] * x_aspt[j];
		// solve: 3. y*x*z aspect
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				yxz_aspt[(i + j) % N] += yx_aspt[i] * z_aspt[j];
		// outputs:
		for (i = 0; i < N; i++)
			printf("%lld ", yxz_aspt[i]);
		printf("\n");
	}
	return 0;
}
