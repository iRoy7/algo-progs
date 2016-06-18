#include <stdio.h>
#define SZ_D 1001

// days: total days
// teams: the num of groups
int days, teams;
int fares[SZ_D];

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_D; i++)
		fares[i] = 0;
}

// st: 0 날부터, 1날부터..
// d: total days
static long double
get_Fares(int st, int d)
{
	long double ret = 2147483647.0;

	while ((d - st) + 1 >= teams)
	{
		int i, sum = 0; 
		for (i = st; i <= d; i++)
			sum += fares[i];

		long double avg_fare = (long double)sum / (d - st + 1);
		if (avg_fare < ret)
			ret = avg_fare;

		// 대여일을 group수를 고려하여 줄여가나면서
		// 
		d--;
	}

	return ret;
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i, j;

	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &days, &teams);
		for (i = 1; i <= days; i++)
			scanf("%d", &fares[i]);

		long double min_fare = 2147483647.0;
		for (j = 1; (days - j) >= teams; j++)
		{
			long double fare = get_Fares(j, days);
			if (fare < min_fare)
				min_fare = fare;
		}

		printf("%.2f\n", min_fare);

		clear_buf();
	}

	return 0;
}
