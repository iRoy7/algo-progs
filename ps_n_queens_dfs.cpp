
#include <stdio.h>
#define MAXIS 11

int n, cnt;
int col[MAXIS];
int icr[2 * MAXIS];
int dcr[2 * MAXIS];

static void
putQueensDFS(int row)
{
	if (row > n) {
	    cnt++; // No. of way which can put all Queues in rows
		return; // back tracking
	}

	for (int i = 1; i <= n; i++) {
		if (!col[i] && !icr[row + i] && !dcr[(row - i) + n]) {
			col[i] = icr[row + i] = dcr[(row - i) + n] = 1; // mark
			putQueensDFS(row + 1);
			col[i] = icr[row + i] = dcr[(row - i) + n] = 0; // un-mark
		}
	}
}
int main()
{
	scanf("%d", &n);
	putQueensDFS(1);
	printf("%d\n", cnt);
	return 0;
}
