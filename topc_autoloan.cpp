/* 
input:
3
6800 100 68
2000 510 4
15000 364 48
=============
outputs:
0.000000
9.652055
7.687856
*/

#include <stdio.h>

int price;
int mth_pay; // monthly payment
int loan_term;

static double
interest_rate()
{
	double balance;
	double high = 100, low = 0, mid = 0;

	while ((1e-9 < high - low) && (1e-9 < (high - low) / high))
	{
		balance = price;
		// x: candidate annual percentage rate of the loan
		mid = (high + low) / 2; 

		for (int i = 0; i < loan_term; i++)
		{
			balance *= mid / 1200 + 1;
			balance -= mth_pay;
		}

		if (0 < balance) high = mid;
		else low = mid;
	}

	return mid;
}

int main()
{
	freopen("autoloan_condition.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d%d", &price, &mth_pay, &loan_term);
		printf("%llf\n", interest_rate());
	}

	return 0;
}
