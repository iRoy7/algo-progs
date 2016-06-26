/*
input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50
===========================
output:
787 23
50 30 23
*/

#include <stdio.h>
#define SZ_N 1001

int N, K;
int arr[SZ_N];

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = arr[(s + e) / 2];
	while (1)
	{
		while (arr[++l] > p);
		while (arr[--r] < p);
		if (l >= r) break;
		tmp = arr[l], arr[l] = arr[r], arr[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &K);
		for (i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		qsort(0, N - 1);

		for (i = 0; i < K; i++)
			printf("%d ", arr[i]);
		printf("\n");

		for (i = 0; i < SZ_N; i++)
			arr[i] = 0;
	}

	return 0;
}
