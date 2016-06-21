// Friends score from TOPCORDER
/* 
input:
4
5
NYNNN
YNYNN
NYNYN
NNYNY
NNNYN
3
NNN
NNN
NNN
3
NYY
YNY
YYN
10
NNNNYNNNNN
NNNNYNYYNN
NNNYYYNNNN
NNYNNNNNNN
YYYNNNNNNY
NNYNNNNNYN
NYNNNNNYNN
NYNNNNYNNN
NNNNNYNNNN
NNNNYNNNNN

====================
output:
4 | 0 | 2 | 8
*/

#include <stdio.h>
#define MAX_F 51

inline int 
max(int a, int b) { return (a > b) ? a : b; }

int main()
{
	freopen("friends_info.txt", "r", stdin);
	setbuf(stdout, NULL); 

	static char FRNS[MAX_F][MAX_F];
	int T, N, i, j, k;
	scanf("%d", &T);

	while (T--) {
		// input
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%s", &FRNS[i]);

		// solve
		int ans = -2147483648;
		for (i = 0; i < N; i++)
		{
			int d_fnd_cnt = 0;
			int ind_fnd_cnt = 0;

			for (j = 0; j < N; j++)
			{
				if (i == j) continue;
				if (FRNS[i][j] == 'Y')
				{
					d_fnd_cnt++;
				}
				else
				{
					for (k = 0; k < N; k++)
					{
						if (FRNS[j][k] == 'Y' && FRNS[k][i] == 'Y')
						{
							ind_fnd_cnt++;
							break; // 한다리 건너서만 친구
						}
					}
				}
			}

			//printf("D1: (%d)th Fr -> d = %d, ind = %d\n", i, d_fnd_cnt, ind_fnd_cnt);
			ans = max(ans, (d_fnd_cnt + ind_fnd_cnt));
		}

		// output
		printf("%d\n", ans);

		// clear buffer
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				FRNS[i][j] = 0;
	}

	return 0;
}
