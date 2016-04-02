#include <stdio.h>
#define MAXIS 100000
int T, N;
long long int total_sum, max_discount;
int data[MAXIS + 10];
inline void qsort(int s, int e) {
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = data[(s + e) / 2];
	while (1) {
		while (data[++l] > p);
		while (data[--r] < p);
		if (l >= r) break;
		tmp = data[l], data[l] = data[r], data[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}
inline long long int cal_discount()
{
	int i, j;
	long long int ret = 0;
	int cnt = N / 3;
	for (i = 1, j = 2; i <= cnt && j < N; i++, j += 3)
		ret += data[j];
	return ret;	
}
int main()
{
	int i, tc;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		// inputs:
		scanf("%d", &N);
		total_sum = 0;
		for (i = 0; i < N; i++) {
			scanf("%d", &data[i]);
			total_sum += data[i];
		}
		// solve: 1. sorting..
		qsort(0, N - 1);
		// solve: 2. calculate max-discount 
		max_discount = cal_discount();
		// outputs:
		printf("#%d %d\n", tc, total_sum - max_discount);
	}
	return 0;
}
