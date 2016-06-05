/*
5
2 3 100 400 200
2 3 100 400 300
5 5 464 464 464
1 4 20 -30 -10
9 1 -1 -10 4
outputs:
1400 1600 4640 -100 0
*/
#include <stdio.h>
#define INT_MIN -2147483648

int nR, nB, oR, oB, bC;

inline int
min(int a, int b) { return (a > b) ? b : a; }
inline int
max(int a, int b) { return (a > b) ? a : b; }

static int
get_max_score()
{
	int i, ans = INT_MIN;
	int change = min(nR, nB);

	for (i = 0; i <= change; i++)
	{
		int score = (nR - i)*oR 
			+ (nB - i)*oB
			+ 2 * i*bC;
		ans = max(ans, score);
	}

	return ans;
}

int main()
{
	freopen("colorful_boxes_and_balls.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc;
	scanf("%d", &T);
	
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d %d%d%d", &nR, &nB, &oR, &oB, &bC);
		printf("Max Scores: %d\n", get_max_score());
	}

	return 0;
}

