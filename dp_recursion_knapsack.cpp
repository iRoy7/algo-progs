// Knapsack problem solution with DT
// input : 
// item : 5, max weight: 10
// W(i) : 3 4 1 2 3
// V(i) : 2 3 2 3 6
// output :
// 14
// item : 3, max weight: 5
// W(i) : 3 2 1
// V(i) : 1 2 3
// output :
// 5
// Knapsack problem solutions
// (1)Recursion
// (2)Recursion with Memoization

#include <stdio.h>
#define SZ_N 51
#define MAX_W 101

int item_w[SZ_N];
int item_v[SZ_N];
int DT[SZ_N][MAX_W];

int N, K;
int max_val;

inline int
max(int a, int b) { return (a > b) ? a : b; }

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < SZ_N; i++)
		item_w[i] = item_v[i] = 0;
}

// recursion without memoization
static void
recur_only(int idx, int total_weight, int total_value)
{
	if (idx > N)
	{
		if (total_value >= max_val)
			max_val = total_value;
		return;
	}
	
	if (total_weight > K) return;

	recur_only(idx + 1, total_weight, total_value);
	recur_only(idx + 1, total_weight + item_w[idx], total_value + item_v[idx]);
}

// from zero weight..after selection, total_weight+item_w[idx]
static int
recur_memo1(int idx, int total_weight)
{
	int &ret = DT[idx][total_weight];
	if (ret != -1) return ret;

	if (idx >= N) return ret = 0;
	else if (total_weight + item_w[idx] > K)
		return ret = recur_memo1(idx + 1, total_weight);

	return ret = max(recur_memo1(idx+1, total_weight),
		recur_memo1(idx + 1, total_weight + item_w[idx])+item_v[idx]);
}

// from r(max weight)..after selection, r - item_w[idx]
static int
recur_memo2(int idx, int r) 
{
	int &ret = DT[idx][r];
	if (ret != -1) return ret;

	if (idx >= N) return ret = 0;
	else if (r < item_w[idx])
		return ret = recur_memo2(idx + 1, r);

	return ret = max(recur_memo2(idx + 1, r),
		recur_memo2(idx + 1, r - item_w[idx]) + item_v[idx]);
}

int main()
{
	freopen("knapsack_problems.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		// inputs:
		scanf("%d%d", &N, &K);
		for (i = 0; i < N; i++)
			scanf("%d", &item_w[i]);
		for (i = 0; i < N; i++)
			scanf("%d", &item_v[i]);

		// DT initializing...
#if 0
		for (i = 0; i < SZ_N; i++)
			for (j = 0; j < MAX_W; j++)
				DT[i][j] = -1; 
#else
		for (i = 0; i < SZ_N*MAX_W; i++)
			*((int*)DT + i) = -1;
#endif

		// solve:
		max_val = -1;
#if 1
		// recursion
		recur_only(0, 0, 0);
		printf("recur_only: max = %d\n", max_val);
#else
		// recursion with memo
#if 0
		// item basis: 0th item, 0th item's weight
		max_val = recur_memo1(0, 0);
		printf("recur_memo: max = %d\n", max_val);
#else
		// max weight basis: 0th item, max weight
		max_val = recur_memo2(0, K);
		printf("recur_memo: max = %d\n", max_val);
#endif

#endif
		// clear buf
		clear_buf();
	}

	return 0;
}
