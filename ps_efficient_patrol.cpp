#include <stdio.h>
#define MAXIS 1000
int n, evn;
int row[MAXIS + 10], col[MAXIS + 10];
int dt[MAXIS + 10][MAXIS + 10];
inline void memory_clear()
{
	for (int i = 0; i < MAXIS + 10; i++)
		for (int j = 0; j < MAXIS + 10; j++)
			dt[i][j] = -1;
}
inline int abs(int a) { return (a > 0) ? a : (-a); }
inline int min(int a, int b) { return (a > b) ? b : a; }
inline int dist(int a, int b)
{
	return abs(row[a] - row[b]) + abs(col[a] - col[b]);
}
inline int minDist(int here, int another)
{
	if (here == evn) return 0;
	int &ret = dt[here][another];
	if (ret != -1) return ret;
	int next = here + 1;
	return ret = min(minDist(next, another) + dist(here, next),
		minDist(next, here) + dist(another, next));
}
inline void construct(int here, int another, int car)
{
	if (here == evn) return;
	int next = here + 1;
	if (minDist(next, another) + dist(here, next) <
		minDist(next, here) + dist(another, next)) {
		printf("%d\n", car);
		construct(next, another, car);
	}
	else {
		printf("%d\n", 3 - car);
		construct(next, here, 3 - car);
	}
}
int main()
{
	scanf("%d %d", &n, &evn), evn++;
	row[0] = col[0] = 1, row[1] = col[1] = n;
	// inputs:
	for (int i = 2; i <= evn; i++) scanf("%d %d", &row[i], &col[i]);
	memory_clear();
	// solve: 1. calculate min distances
	int a = minDist(2, 1) + dist(0, 2);
	int b = minDist(2, 0) + dist(1, 2);
	//printf("%d %d\n", a, b);
	// outputs:
	printf("%d\n", min(a, b));
	if (a < b) {
		puts("1");
		construct(2, 1, 1);
	}
	else {
		puts("2");
		construct(2, 0, 2);
	}
	return 0;
}
