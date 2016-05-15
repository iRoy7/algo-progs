#include <stdio.h>
#include <time.h>
#define MAXIS 100
int n, k;
int dt[MAXIS + 1][MAXIS+1];
inline int min(int a, int b) { return (a > b) ? b : a; }

static int 
bin(int n, int k)
{
	if (k == 0 || n == k) return 1;
	else
		return  bin(n - 1, k - 1) + bin(n - 1, k);
}

static int
binDp(int n, int k)
{
	if (k == 0 || n == k) return 1;
	int i, j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i)
				dt[i][j] = 1;
			else
				dt[i][j] = dt[i - 1][j - 1] + dt[i - 1][j];
		}
	}
	return dt[n][k];
}

int main()
{
	clock_t start_p, end_p;
	setbuf(stdout, NULL);
	scanf("%d %d", &n, &k);

	// solve: get the number of binominal coefficent
	start_p = clock();
	int ret1 = bin(n, k);
	printf("%d\n", ret1);
	end_p = clock();
	printf("...speed %f sec.\n", ((double)(end_p - start_p) / CLOCKS_PER_SEC));
	
	// solve: get the number of binominal coefficent with DP
	start_p = clock();
	int ret2 = binDp(n, k);
	printf("%d\n", ret2);
	end_p = clock();
	printf("...speed %f sec.\n", ((double)(end_p - start_p) / CLOCKS_PER_SEC));

	return 0;
}
