// boundary between West and East
// inputs: 
// WE
// WWWE
// WEEE
// WEWWWE
// WEWWWE
// outputs:
// 1|2
// 1|2
// 5|6
#include <stdio.h>
#define MAX_CULTS 101 // cultures -> ROW
#define MAX_DISTS 10010 // districts -> COL
int N, M; // N: disrict , M: cultures
int a[MAX_CULTS][MAX_DISTS];
int E[MAX_DISTS], W[MAX_DISTS], EN[MAX_DISTS], WN[MAX_DISTS];

static void 
clear_memory()
{
	int i, j;
	for (i = 0; i <= N; i++)
		E[i] = W[i] = EN[i] = WN[i] = 0;
	for (i = 0; i <= M; i++)
		for (j = 0; j <= N; j++)
			a[i][j] = 0;
}

int main() 
{
	int T, tc, i, j;
	freopen("cultures_info.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &M);
		for (i = 1; i <= M; i++) {
			for (j = 1; j <= N; j++) {
				scanf(" %c", &a[i][j]);
				if (a[i][j] == 'W') W[j]++;
				else E[j]++;
				WN[0] += W[j];
			}
		}
		//printf("Accumulation of W Number = %d\n", WN[0]);
		int min = WN[0];
		int divided_idx = 0;
		for (i = 1; i <= N; i++) {
			EN[i] = EN[i - 1] + E[i];
			WN[i] = WN[i - 1] - W[i];
			if ((EN[i] + WN[i]) < min) {
				min = EN[i] + WN[i];
				divided_idx = i;
			}
		}
		printf("#%d %d | %d\n", tc, divided_idx, divided_idx + 1);
		clear_memory();
	}
	return 0;
}
