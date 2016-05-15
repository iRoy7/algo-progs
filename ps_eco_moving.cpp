// Eco moving
// inputs:
// 1 <- test cases
// 4 3 3 <- W, H, N
// 1 1
// 3 3
// 4 1
// outputs:
// 5
#include <stdio.h>
#define MAX_MAP 10010
#define MAX_N 1010
struct Crossroad {
	int y, x;
};
struct Crossroad cross[MAX_N];

int W, H, N;

inline int abs(int a) { return (a > 0)? a : (-a); }

static int
diagonal_paths(int y1, int y2, int x1, int x2) {
	// move (y1, x1)->(y2, x2)
	int path_cnt = 0;
	while ((y1 < y2 && x1 < x2) || (y1 > y2 && x1 > x2)) {
		path_cnt++;
		if (y1 < y2 && x1 < x2) y1++, x1++;
		else y2++, x2++;
	}
	return path_cnt;
}

static void
clear_memory() {
	for (int i = 0; i < MAX_N; i++)
		cross[i].y = 0, cross[i].x = 0;
}
int main()
{
	freopen("moving_info.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T, tc, i, j;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		int min_fare = 0;
		// inputs:
		scanf("%d %d %d", &W, &H, &N);
		for (i = 0; i < N; i++)
			scanf("%d %d", &cross[i].x, &cross[i].y);
		// solves:
		for (i = 1; i < N; i++) {
			int dist = abs(cross[i - 1].y - cross[i].y)
				+ abs(cross[i - 1].x - cross[i].x);
			int diag = diagonal_paths(cross[i - 1].y, cross[i].y,
				cross[i - 1].x, cross[i].x);
			min_fare += dist - diag;
		}
		// ouputs:
		printf("#%d %d\n", tc, min_fare);
		
		// clear memory
		clear_memory();
	}
	return 0;
}
