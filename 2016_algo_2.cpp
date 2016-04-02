#include <stdio.h>
#define MAXIS 100
struct Wire { int a, b; };
struct Wire w[MAXIS + 1];
int n;
int dt[MAXIS + 1];
inline void memory_clear()
{
	for (int i = 0; i < MAXIS + 1; i++)
		w[i].a = 0, w[i].b = 0, dt[i] = 0;
}
inline void qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p;
	struct Wire tmp;
	l = s - 1, r = e + 1, p = w[(s + e) / 2].a;
	while (1) {
		while (w[++l].a < p);
		while (w[--r].a > p);
		if (l >= r) break;
		tmp = w[l], w[l] = w[r], w[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}
int main()
{
	int i, j;
	setbuf(stdout, NULL);
	scanf("%d", &n), memory_clear();
	// inputs:
	for (i = 0; i < n; i++)
		scanf("%d %d", &w[i].a, &w[i].b);
	// solve: 1. sorting
	qsort(0, n - 1);
	// solve: 2. LIS
	int max_so_far = 0;
	for (i = 0; i < n; i++) {
		dt[i] = 1;
		for (j = 0; j < i; j++) {
			if (w[i].b > w[j].b && dt[i] < dt[j] + 1)
				dt[i] = dt[j] + 1;
		}
		if (max_so_far < dt[i])
			max_so_far = dt[i];
	}
	// outputs:
	printf("%d\n", n - max_so_far);
	return 0;
}
