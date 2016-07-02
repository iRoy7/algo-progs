/*

From GeeksforGeeks Practices.
We have N persons sitting on a round table. 
Any person can do a handshake with any other person. 
In how many ways these N people can make handshakes 
so that no two handshakes crosses each other. 
N would be even.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:
Print number of ways.

Constraints:
1<=T<=20, 2<=N<=30

N: 6

Host -> 2 || Host -> M
count += DT[M-2] * DT[2];

Others
who is one of Left {2 ~ 3} && Right {5 ~ 6}
count += DT[w-2] * DT[M-w];

*/

#include <stdio.h>
#define SZ_N 31

int DT[SZ_N];

static void
generate_hs_cnt()
{
	int i, j, M, hs_cnt;
	
	DT[0] = 0, DT[2] = 1;
	M = 0; //// people

	for (i = 2; (i * 2) <= SZ_N-1; i++)
	{
		M = i * 2;
		// count of hand shaking
		hs_cnt = 0;

		for (j = 1; j * 2 <= M; j++)
		{
			// host(1) -> who
			int w = j * 2;

			if (w == 2 || w == M)
				hs_cnt += DT[M - 2] * DT[2];
			else if (w > 2 && w <= (M - 2))
				hs_cnt += DT[w - 2] * DT[M - w];
		}

		DT[M] = hs_cnt;
	}
}

int main()
{
	setbuf(stdout, NULL);

	generate_hs_cnt();

	int T, tc, N;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input:
		scanf("%d", &N);

		// output:
		printf("%d\n", DT[N]);
	}

	return 0;
}
