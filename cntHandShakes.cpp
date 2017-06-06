/* Count how many hand shakes are possible */

#include <stdio.h>
const int SN = 51;

int main()
{
	int T; scanf("%d", &T);
	long long DT[SN]; // Dynamic Table

	for (int tc = 1; tc <= T; tc++)
	{
		printf("How many peoples there?> ");
		int N; scanf("%d", &N); // How many people
		if (N%2 || N > SN)
		{
			printf("Wrong members! Should be even! Try again!\n");
			continue;
		}

		int M = 0; // People index
		DT[0] = 0, DT[2] = 1;

		for (int i = 2; i * 2 <= N; i++)
		{
			int cntHS = 0; // count of Hand Shakes
			M = i * 2;

			for (int j = 1; j * 2 <= M; j++)
			{
				int w = j * 2;	// host(1) -> who

				if (w == 2 || w == M)
					cntHS += DT[M - 2];
				else if (w > 2 && w <= M - 2)
					cntHS += DT[w - 2] * DT[M - w];

				DT[M] = cntHS;
			}
		}

		printf("DT[%d] = %d\n", N, DT[N]);
	}

	return 0;
}