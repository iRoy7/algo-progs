/*
3
100 20 8
40 50 60
37 48 55
100 48 50
105 48 47
110 50 52
110 50 52
110 51 54
109 49 53
1000 0 2
10 20 30
15 24 32
1000 0 2
10 9
outputs:
239 500 0
*/

#include <stdio.h>
#include <cmath>

#define SZ_M 51
#define SZ_C 1001

int init_invst; // init investment
int monthly_contr; // monthly contribution
int for_mth; // for months
char stocks[SZ_M][SZ_C];

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < SZ_M; i++)
		for (j = 0; j < SZ_C; j++)
			stocks[i][j] = 0;
}

static int
maximum_earnings()
{
	int money = init_invst;
	int month = for_mth;
	int corp = 1;
	char *s = stocks[0];
	while (*s++) if (*s == ' ') corp++;

	//printf("D1: corp = %d\n", corp);

	int price[SZ_M][SZ_C];
	double max = 0, profit = 0;
	double proportion[SZ_M] = { 0 };
	bool buy[SZ_M] = { false };

	int i, j;
	for (i = 0; i < month; i++)
	{
		char *str = stocks[i];
		int corp_idx = 0;
		char s[4] = { 0 };
		int s_cnt = 0;

		for (j = 0; ; j++)
		{
			int ret;
			if (str[j] == '\0')
			{
				s[s_cnt] = '\0';
				sscanf(s, "%d", &ret);
				//printf("last = %d\n", ret);
				price[i][corp_idx++] = ret;
				break;
			}
			else if (str[j] != ' ')
			{
				s[s_cnt++] = str[j];
			}
			else if (str[j] == ' ')
			{
				s[s_cnt] = '\0';
				sscanf(s, "%d", &ret);
				//printf("%d st  = %d\n", corp_idx, ret);
				price[i][corp_idx++] = ret;
				s_cnt = 0;
			}
		}
	}

	for (i = month - 2; 0 <= i; i--)
	{
		for (j = 0; j < corp; j++)
		{
			double p =
				(1.0 * price[month - 1][j] / price[i][j]) - 1;
			if (0 < p && max < p)
			{
				buy[i] = true;
				max = p;
				proportion[i] = p;
			}
		}
	}

	for (i = 0; i < month; i++)
	{
		if (buy[i])
		{
			//printf("D2: i month = %d\n", i);
			profit += (double)money * proportion[i];
			money = 0;
		}
		money += monthly_contr;
	}

	//printf("profit = %f\n", profit);
	return (int)round(profit);
}

int main()
{
	freopen("stock_history.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d%d", &init_invst, &monthly_contr, &for_mth);
		for (i = 0; i < for_mth; i++)
			scanf(" %[^\n]\n", &stocks[i]);

		printf("%d\n", maximum_earnings());

		clear_buf();
	}

	return 0;
}
