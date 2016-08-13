#include <stdio.h>
#define SZN 101
#define NMAX 100
#define INT_MIN -2147483648
#define max(a,b)(((a)>(b))?(a):(b))

int arr[SZN][SZN];
int N;

int sum_hv()
{
	int i, j;
	int sub_sum = INT_MIN;
	
	// horizontal
	for (i = 0; i < N; i++)
	{
		int row_sum = 0;

		for (j = 0; j < N; j++)
			row_sum += arr[i][j];

		sub_sum = max(sub_sum, row_sum);
	}
	
	// vertical
	for (j = 0; j < N; j++)
	{
		int col_sum = 0;

		for (i = 0; i < N; i++)
			col_sum += arr[i][j];

		sub_sum = max(sub_sum, col_sum);
	}

	return sub_sum;
}

int sum_diag()
{
	int i, j;
	int sub_sum = INT_MIN;
	
	// incremental diagonal
	int icr_sum = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (N - 1 == (i + j))
				icr_sum += arr[i][j];
		}
	}
	
	sub_sum = max(sub_sum, icr_sum);
	
	// decremental diagonal
	int dcr_sum = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (N - 1 == (i - j + (N - 1)))
				dcr_sum += arr[i][j];
		}
	}

	sub_sum = max(sub_sum, dcr_sum);

	return sub_sum;
}

int main()
{
	int T, tc, i, j;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				arr[i][j] = 0;
				scanf("%d", &arr[i][j]);
			}
		}

		int ans = INT_MIN;
		ans = max(ans, sum_hv());
		ans = max(ans, sum_diag());

		printf("%d\n", ans);
	}

	return 0;
}
