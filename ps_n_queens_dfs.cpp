Enter file contents here#include <stdio.h>
#define MAXIS 11
int n, cnt;
int col[MAXIS];
int icr[2 * MAXIS];
int dcr[2 * MAXIS];

static void
putQueensDFS(int r)
{
	if (r > n) {
	    cnt++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!col[i] && !icr[r + i] && !dcr[(r - i) + n]) {
			col[i] = icr[r + i] = dcr[(r - i) + n] = 1;
			putQueensDFS(r + 1);
			col[i] = icr[r + i] = dcr[(r - i) + n] = 0;
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
