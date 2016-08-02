#include <stdio.h>
#define SZ_N 100001

int C[SZ_N];
int N;

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = C[(s + e) / 2];
	while (1)
	{
		while (C[++l] > p);
		while (C[--r] < p);
		if (l >= r) break;
		tmp = C[l], C[l] = C[r], C[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static long long 
get_Discount()
{
	int i, j;
	long long ret = 0;
	int cnt = N / 3;
	
	for (i = 1, j = 2; (i <= cnt) && (j < N); i++, j += 3)
		ret += C[j];
	
	return ret;
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i;
	long long total_sum, max_discnt;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++ )
	{
		scanf("%d", &N);

		total_sum = 0;
		for (i = 0; i < N; i++)
		{
		  C[i] = 0;
			scanf("%d", &C[i]);
			total_sum += C[i];
		}

		qsort(0, N - 1);

		max_discnt = 0;
		max_discnt = get_Discount();

		//printf("%lld\n", max_discnt);
		printf("%lld\n", total_sum - max_discnt);
	}

	return 0;
}
