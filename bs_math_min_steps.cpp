/*
(step) ------ (max distance)
0 - 0
1 - 1
2 - 2
3 - 4
...
INPUT
8                                                                                             
45 48
45 49
45 50
45 51
45 52
45 53
45 54
45 55
OUTPUT
3
3
4
4
5
5
6

*/

#include <stdio.h>

int main()
{
	freopen("minimum_steps.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, d, from, to;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &from, &to);

		int dist = 0;
		dist = to - from;
		printf("Dist=(%d)\n", dist);

		for (i = 0, d = 0; (d + i) < dist; i++)
		{
			d += i / 2;
			printf("    -> step = (%d) + d =(%d) = %d\n", i, d, i+d);
		}
			
		printf("%d steps\n", i);
	}

	return 0;
}
