/*
inputs:
2
3 4
1 2 3 2
1 1 2
3 2 2
1 1 3
2 2 2
-------------
outputs:
3 | 4| 5
*/

#include <stdio.h>
#define SZ_N 51
#define SZ_G 101

int players[SZ_N];
int suspects[SZ_G];
int N, M;

static void
clear_buf()
{
	int i;
	for (i = 0; i < N + 1; i++)
		players[i] = 0;
	for (i = 0; i < M + 1; i++)
		suspects[i] = 0;
}

int main()
{
	setbuf(stdout, NULL);
	
	int T, tc, i, j;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// inputs
		scanf("%d%d", &N, &M);

		/* Save the suspects info to suspects array*/	
		for (i = 0; i < M; i++)
			scanf("%d", &suspects[i]);

		// solve
		/* Play games */
		for (i = 0; i < M; i++)
		{
			/* suspect get 1 point always */
			int curr_suspt = suspects[i];
			players[curr_suspt]++;

			/* get the answers from players*/
			/* player : 1, 2, 3 ... */
			int losers = 0;
			for (j = 1; j <= N; j++)
			{
				int x; 
				scanf("%d", &x);
				
				/* get the points if answer == suspect in this game */
				if (x == curr_suspt && j != curr_suspt)
					players[j]++;
				/* count players who write wrong answer */
				else if (j != curr_suspt)
					losers++;
			}

			/* current suspect gets more points from losers */
			players[curr_suspt] += losers;
		}

		// output
		/* print each player's game point */
		for (i = 1; i <= N; i++)
			printf("%d ", players[i]);
		printf("\n");

		// clear buffer for next games
		clear_buf();
	}

	return 0;
}
