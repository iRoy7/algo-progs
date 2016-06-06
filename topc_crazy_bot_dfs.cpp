// Crazy Bot from TOPCORDER
// explorer path via DFS
// constraints:
// east, west, south, north : 0~100
// start poiint : 50, 50
/* 
input:
6
7
50 0 0 50
1
25 25 25 25
2
25 25 25 25
7
50 0 0 50
14
50 50 0 0
14
25 25 25 25
======================
output:
1.000000
1.000000
0.750000
1.000000
0.000122
0.008845
*/

#include <stdio.h>
#define MAX_M 101

double prob[4];
bool MAP[MAX_M][MAX_M];
// east->west->south->north
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

static double
get_prob(int x, int y, int n)
{
	// base cases;
	if (MAP[x][y]) return 0.0;
	if (n == 0) return 1.0;

	MAP[x][y] = true;
	double ret = 0.0;

	// 4 방향 탐색
	for (int i = 0; i < 4; i++)
	{
		ret += get_prob(x + dx[i], y + dy[i], n - 1) * prob[i];
	}

	MAP[x][y] = false;

	return ret;
}

static void
clear_buf()
{
	for (int i = 0; i < MAX_M; i++)
		for (int j = 0; j < MAX_M; j++)
			MAP[i][j] = 0;

	prob[0] = prob[1] = prob[2] = prob[3] = 0.0;
}

int main()
{
	freopen("robot_direct_prob_info.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, N, i;
	scanf("%d", &T);

	while (T--) 
	{
		scanf("%d", &N);
		// east->west->south->north
		for (i = 0; i < 4; i++)
		{
			int x;
			scanf("%d", &x);
			prob[i] = x / 100.0;
		}

		double ans = 0.0;
		ans = get_prob(50, 50, N);

		printf("%f\n", ans);

		clear_buf();
	}

	return 0;
}
