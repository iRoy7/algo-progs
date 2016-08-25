#include <stdio.h>
#define SZN 11
#define INT_MAX 2147483647
#define ABS(a) (((a) < (0))?-(a):(a))

/////////////////////////////////////////////////////////////////
// POWER SET::
// 2^n (= 1 << n)
int data[4] = { 1, 2, 3, 4 };
int flag[4] = { 0, 0, 0, 0 };

void recurr_PwrSet(int n, int depth)
{
	if (n == depth)
	{
		printf("{");
		for (int i = 0; i < n; i++)
		{
			if (flag[i] == 1) printf("%d", data[i]);
			else printf(".");
		}
		printf("}\n");
		return;
	}

	flag[depth] = 1;
	recurr_PwrSet(n, depth + 1);
	flag[depth] = 0;
	recurr_PwrSet(n, depth + 1);
}


int Src[SZN] = { -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 };
int trr[SZN];

void PwrSet_ZeroSum()
{
	int i, j, k, h;
	int n = sizeof(Src) / sizeof(int);

	for (i = 0; i < (1 << n); i++)
	{
		int zero_sum = 0;
		int subset_cnt = 0;

		for (j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				zero_sum += Src[j];
				trr[subset_cnt++] = Src[j];
			}
		}

		if (zero_sum == 0 && subset_cnt > 0)
		{
			for (k = 0; k < subset_cnt; k++)
				printf("%d ", trr[k]);
			printf("\n");
		}

		for (h = 0; h < SZN; h++)
			trr[h] = 0;
	}
}


int main()
{
	// Recursion PowerSet
	printf("Recursion Powerset:\n");
	recurr_PwrSet(sizeof(data) / sizeof(int), 0);
	printf("\n");

	// Iterative PowerSet
	printf("Iterative Powerset(Binary Counting):\n");
	static int src[] = { 1, 2, 3, 4 };
	static int trr2[4] = { 0, };
	
	int n = sizeof(src) / sizeof(int);

	for (int i = 0; i < (1 << n); i++)
	{
		printf("{");
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				printf("%d", src[j]);
				trr2[j] = src[j];
			}
			else
			{
				trr2[j] = -1;
				printf(".");
			}
		}
		printf("}\n");

		printf("      -->> trr {");
		for (int k = 0; k < n; k++)
		{
			printf("%d ", trr2[k]);
		}
		printf("}\n");

	}

	PwrSet_ZeroSum();

	return 0;
}
