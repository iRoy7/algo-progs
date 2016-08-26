#include <stdio.h>
#define SZN 11

int main()
{
	static int Src[] = { -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 };
	int trr[SZN];
	int cnt = 0;

	int n = sizeof(Src) / sizeof(int);
	printf("n = (%d)\n", n);

	for (int i = 0; i < (1 << n); i++)
	{
		int zeroSum = 0;
		int subsetCnt = 0;
		int existCnt = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				zeroSum += Src[j];
				trr[subsetCnt++] = Src[j];
				existCnt++;
			}
		}

		if (existCnt == 3 && zeroSum == 0 && subsetCnt > 0)
		{
			cnt++;
			printf("{ ");
			for (int k = 0; k < subsetCnt; k++)
				printf("%d ", trr[k]);
			printf(" }\n");
		}
	}

	printf("Combi Set Cnt = (%d)\n", cnt);

	return 0;
}
