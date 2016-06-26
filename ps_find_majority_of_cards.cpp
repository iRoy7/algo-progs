/*
Boundary of card numer: -2^62 < number < 2^62
Boundary of cards count: 1 <= N <= 1000000
input:
1
10 
9 8 7 6 5 4  3 2 1 3
output:
3
*/

#include <stdio.h>
#define SZ_N 1000001

int N;
long long cards[SZ_N];
long long major_card;

static void 
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r;
	long long p, tmp;
	l = s - 1, r = e + 1, p = cards[(s + e) / 2];
	while (1)
	{
		while (cards[++l] < p);
		while (cards[--r] > p);
		if (l >= r) break;
		tmp = cards[l], cards[l] = cards[r], cards[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static void
print_cards()
{
	int i;
	for (i = 1; i <= N; i++)
		printf("%d ", cards[i]);
	printf("\n");
}

static long long
find_majority_of_cards()
{
	int i;
	int prev_dp_cnt = 0, cnt = 1;
	long long card = 0;

	for (i = 1; i <= N; i++)
	{
		if (cards[i] == cards[i - 1])
			cnt += 1;
		else
		{
			if (prev_dp_cnt < cnt)
			{
				prev_dp_cnt = cnt;
				card = cards[i - 1];
			}
			cnt = 1;
		}
	}

	// for the last card
	if (prev_dp_cnt < cnt)
	{
		prev_dp_cnt = cnt;
		card = cards[N - 1];
	}

	return card;
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			scanf("%lld", &cards[i]);

		// solve
		/* qsort first */
		qsort(1, N);
		/* find the majority of cards */
		//print_cards();
		major_card = find_majority_of_cards();

		// output
		printf("%lld\n", major_card);

		// clear buf
		for (i = 0; i < N; i++)
			cards[i] = 0;
	}

	return 0;
}
