// Cryptography from TOPCORDER
#include <stdio.h>
#define SZ_C 51

int NUMS[SZ_C];

static void 
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = NUMS[(s + e) / 2];
	while (1) 
	{
		while (NUMS[++l] < p);
		while (NUMS[--r] > p);
		if (l >= r) break;
		tmp = NUMS[l], NUMS[l] = NUMS[r], NUMS[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

int main()
{
	freopen("numbers.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, N, i;
	scanf("%d", &T);

	while (T--) 
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &NUMS[i]);
		
		qsort(0, N - 1);

		long long ans = 1;
		for (i = 0; i < N; i++)
		{
			if (i == 0) NUMS[i]++;
			ans *= NUMS[i];
		}

		printf("%lld\n", ans);
	}
	return 0;
}
