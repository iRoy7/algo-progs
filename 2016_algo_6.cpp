#include <stdio.h>
#define MAXIS 1000000
int T;
char qKey[MAXIS + 10];
char dWord[MAXIS + 10];
int wNum;
// {[a][min], [a][max]}
int a[8][3] = { 
	{97, 99}, {100, 102}, {103, 105}, {106, 108}, {109, 111},
	{112, 115}, {116, 118}, {119, 122} };
inline void memory_clear()
{
	for (int i = 0; i < 1000010; i++)
		qKey[i] = 0, dWord[i] = 0;
}
int main()
{
	int i, j, tc;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {		
		memory_clear();
		// inputs:		
		scanf("%s %d", qKey, &wNum);
		// solve: 1. create total min/max
		int min = 0, max = 0;
		for (i = 0; qKey[i]; i++) {
			int x = qKey[i] - '0';
			min += a[x - 2][0];
			max += a[x - 2][1];
		}
		//printf("%d %d\n", min, max);
		// solve: 2. check boundary
		int valid_w_cnt = 0;
		for (i = 0; i < wNum; i++) {
			scanf("%s", dWord);
			//printf("%s\n", dWord);
			int sum = 0;
			for (j = 0; dWord[j]; sum += dWord[j], j++);
			//printf("%d\n", sum);
			if (min <= sum && sum <= max)
				valid_w_cnt++;
		}		
		// outouts:
		printf("#%d %d\n", tc, valid_w_cnt);
	}
	return 0;
}
