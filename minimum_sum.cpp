#include <stdio.h>
#define MAXIS 11

int N;
int TI[MAXIS][MAXIS];
int COL[MAXIS];
int minSum = 2147483647;

static void
minSumDFS(int r, int sum)
{
	if (r == N) {
		if (minSum > sum) minSum = sum;
		return;
	}
	for (int i = 0; i < N; i++) {
#if 0 // except the selected column
		if (!COL[i]) {
			COL[i] = 1; // mark;
			minSumDFS(r + 1, sum + TI[r][i]);
			COL[i] = 0; // unmark;
		}
#else // all cases
		minSumDFS(r + 1, sum + TI[r][i]);
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
