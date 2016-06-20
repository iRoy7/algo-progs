#include <stdio.h>
#define SZ_N 11

int N;
int TI[SZ_N][SZ_N];
int COL[SZ_N];
int minSum = 2147483647;

static void
minSumDFS(int row, int sum)
{
	if (row == N) {
		if (sum < minSum) minSum = sum;
		return;
	}
	
	for (int i = 0; i < N; i++) {
#if 0 // except the selected column
		if (!COL[i]) {
			COL[i] = 1; // mark;
			minSumDFS(row + 1, sum + TI[row][i]);
			COL[i] = 0; // unmark;
		}
#else // all cases
		minSumDFS(row + 1, sum + TI[row][i]);
#endif
	}
	
	return;
}

int main()
{
	setbuf(stdout, NULL);
	scanf("%d", &N);
	
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &TI[i][j]);
	
	minSumDFS(0, 0);
	
	printf("minSum = %d\n", minSum);
	
	return 0;
}
