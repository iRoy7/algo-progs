/*
input:
4
1 1 0 1
0 1 0 0
1 0 1 0
1 0 0 0
5
1 1 0 1 1
0 1 0 0 0
1 0 1 0 1
1 0 0 0 0
1 0 1 1 1
----------------------
output:
2  | 4
10 | 7
*/

#include <stdio.h>
#define SZ_N 11

int N;

// Queens
int max_q_cnt;
int col[SZ_N];
int icr[2 * SZ_N];
int dcr[2 * SZ_N];

static void
put_Queens_dfs(int row)
{
	// bases cases..exit condition for backtracking
	if (row > N)
	{
		max_q_cnt++; // No. of ways which can put all Queens in rows.
		return; // back tracking
	}

	int i;
	for (i = 1; i <= N; i++)
	{
		if (!col[i] && !icr[row + i] && !dcr[(row - i) + N])
		{
			col[i] = icr[row + i] = dcr[(row - i) + N] = 1; // mark
			put_Queens_dfs(row + 1);
			col[i] = icr[row + i] = dcr[(row - i) + N] = 0; // un-mark
		}
	}
}

// Bishops
int max_b_cnt;
int board[SZ_N][SZ_N];
bool dc[2 * SZ_N];

static int
put_Bishop_dfs(int icr)
{
	// bases cases..exit condition for backtracking
	if (icr >= 2 * N - 1) 
		return 0;

	int y = (icr < N) ? icr : N - 1;
	int x = (icr < N) ? 0 : icr - (N - 1);

	int max = -2147483648;

	while (y >= 0 && x < N)
	{
		if (board[y][x] == 1 && dc[(y - x) + N] == false)
		{
			dc[(y - x) + N] = true; // mark
			int m = put_Bishop_dfs(icr + 2) + 1;
			dc[(y - x) + N] = false; // un-mark
			max = (max < m) ? m : max;
		}
		y = y - 1;
		x = x + 1;
	}

	if (max < 0) max = put_Bishop_dfs(icr + 2);

	return max;
}

int main()
{
	scanf("%d", &N);

	// put Queens
	put_Queens_dfs(1);
	printf("%d\n", max_q_cnt);

	// put Bishops
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	max_b_cnt = put_Bishop_dfs(0) + put_Bishop_dfs(1);
	printf("%d\n", max_b_cnt);

	return 0;
}
