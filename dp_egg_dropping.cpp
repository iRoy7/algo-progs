#include <stdio.h>
#define SZ_N 101
#define INT_MAX 2147483647

int n, k;
int DT[SZ_N][SZ_N];

inline int
max(int a, int b) { return (a > b) ? a : b; }

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < k; j++)
			DT[i][j] = 0;
}

static int
drop_eggs()
{
	int res;
	int i, j, x; // i-> eggs, j -> floors
	// We need one trial for on floor and zero trial for zero floor
	for (i = 1; i <= n; i++)
	{
		DT[i][1] = 1;
		DT[i][0] = 0;
	}
	// We always need j trials for one egg and j floors
	for (j = 1; j <= k; j++)
		DT[1][j] = j;
	// Fill rest of the entries in table using optimal substructure
	// property
	for (i = 2; i <= n; i++)
		for (j = 2; j <= k; j++)
		{
			DT[i][j] = INT_MAX;
			for (x = 1; x <= j; x++)
			{
				// two cases:
				// breaks: the problem reduces 
				//         to x-1 floors and n-1 eggs
				// not breaks: the problem reduces
				//         to k-x floors and n eggs
				res = 1 + max(DT[i - 1][x - 1], DT[i][j - x]);
				if (res < DT[i][j])
					DT[i][j] = res;
			}
		}

	return DT[n][k];
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &n, &k);
		printf("\n Minimum number of trials in worst cases with %d eggs %d floors is %d\n", n, k, drop_eggs());
		clear_buf();
	}

	return 0;
}
