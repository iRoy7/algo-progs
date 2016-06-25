#include <stdio.h>
#define SZ_N 101

struct Wire { int a, b; };
struct Wire w[SZ_N];
int N;

// Dynamic Table
// 0, 1, 2 번째까지의 LIS의 길이
int DT[SZ_N];

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_N; i++)
		w[i].a = w[i].b = DT[i] = 0;
}

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p; 
	struct Wire tmp;
	l = s - 1, r = e + 1, p = w[(s + e) / 2].a;

	while (1)
	{
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
	freopen("linked_wires.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j, max_so_far;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d%d", &w[i].a, &w[i].b);

		qsort(0, N - 1);
		
		max_so_far = 0;
		for (i = 0; i < N; i++)
		{
			DT[i] = 1;
			for (j = 0; j < i; j++)
			{
				if (w[i].b > w[j].b && DT[i] < DT[j] + 1)
					DT[i] = DT[j] + 1;
			}

			if (max_so_far < DT[i])
				max_so_far = DT[i];
		}

		printf("%d\n", N - max_so_far);

		clear_buf();
	}

	return 0;
}
