/* Find Minimum Travel Expense */

#include <stdio.h>
const int SN = 101000;
const int IMAX = 2147483647;
long long DT[SN];			// Dynamic Table
long long PS[SN];			// Prefix Sum
long long Cost[SN][4];		// Cost
int N, M;					// N: City, M: Days

void makePS()
{ // Make Prefix Sum Table
	PS[0] = 0, PS[1] = PS[0] + DT[1];
	for (int i = 2; i < N + 1; i++)
		PS[i] = PS[i - 1] + DT[i];
}

long long findMinExp()
{
	long long totalExp = 0;
	for (int i = 0; i < N + 1; i++)
	{
		if (PS[i])
		{
			long long cash = 0, card = 0;
			cash = Cost[i][0] * PS[i];
			card = Cost[i][2] + Cost[i][1] * PS[i];
			(cash < card) ? totalExp += cash : totalExp += card;
		}
	}

	return totalExp;
}

int main()
{
	freopen("calcMinTravelExp.txt", "r", stdin);

	int T; scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);

		int prevTN = 0; // Previous Train Number
		for (int i = 0; i < M; i++)
		{
			int x; scanf("%d", &x);

			if (prevTN != 0 && x != 0)
			{
				if (prevTN < x)
					DT[prevTN]++, DT[x]--;
				else
					DT[x]++, DT[prevTN]--;

				prevTN = x;
			}
			else
				prevTN = x;

			makePS();
		}

		for (int i = 1; i < N; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			Cost[i][0] = a, Cost[i][1] = b, Cost[i][2] = c;
		}

		printf("%lld\n", findMinExp());
	}

	return 0;
}