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

#include <stdio.h>
#define SZ_N 51

int ITW[SZ_N];
int ITV[SZ_N];
int DT[SZ_N][10 * SZ_N];

int N, W;
inline int
max(int a, int b) { return (a > b) ? a : b; }

static int 
packing(int i, int cur_w)
{
	int &ret = DT[i][cur_w];
	if (ret != -1) return ret;

	// base cases;
	if (i == N + 1) return ret = 0;
	else if (cur_w + ITW[i] > W) return ret = packing(i + 1, cur_w);

	return ret = max(packing(i + 1, cur_w), packing(i + 1, cur_w + ITW[i]) + ITV[i]);
}

static int
packing2(int i, int r)
{
	int &ret = DT[i][r];
	if (ret != -1) return ret;

	// base cases;
	if (i == N + 1) return ret = 0;
	else if (r < ITW[i]) return ret = packing2(i + 1, r);

	return ret = max(packing2(i + 1, r), packing2(i + 1, r - ITW[i]) + ITV[i]);
}

static void
clear_buf()
{
	for (int i = 0; i < SZ_N; i++)
		ITW[i] = ITV[i] = 0;
}

int main()
{
	freopen("knapsack_items.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &W);
		for (i = 1; i <= N; i++)
			scanf("%d", &ITW[i]);
		for (i = 1; i <= N; i++)
			scanf("%d", &ITV[i]);
		// initialize DT
		for (i = 0; i < SZ_N; i++)
			for (j = 0; j < 10 * SZ_N; j++)
				DT[i][j] = -1;

		// get the max valures
		unsigned max = 0;

		max = packing(1, 0);
		//max = packing2(1, W);

		printf("#%d %d\n", tc, max);

		clear_buf();			
	}

	return 0;
}

