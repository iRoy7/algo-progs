// Friends score from TOPCORDER

#include <stdio.h>
#define MAX_F 51

inline int max(int a, int b) { return (a > b) ? a : b; }

int main()
{
	freopen("friends_info.txt", "r", stdin);
	setbuf(stdout, NULL); 

	int T, N, i, j, k;
	static char FRNS[MAX_F][MAX_F];
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%s", &FRNS[i]);

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

		printf("%d\n", ans);

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				FRNS[i][j] = 0;
	}

	return 0;
}
