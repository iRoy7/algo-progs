#include <stdio.h>
#define INT_MAX 2147483647
#define ABS(a) (((a) < (0))?-(a):(a))

int arr[7] = { 1, 60, -10, 70, -80, 85 };
int trr[7] = { 0, };
int mA, mB;
int close_zero_val;

/////////////////////////////////////////////////////////////////
// PERMUTATION::
// nPn = n!
// nPr = n x (n-1) x ... x (n - r + 1)
static void
recurr_Permu(int n, int r)
{
	if (r == 0)
	{
		if (close_zero_val > ABS(trr[0] + trr[1]))
		{
			close_zero_val = ABS(trr[0] + trr[1]);
			mA = trr[0], mB = trr[1];
		}
	}
	else
	{
		int i, tmp;
		for (i = n - 1; i >= 0; i--)
		{
			tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
			trr[r - 1] = arr[n - 1];
			recurr_Permu(n - 1, r - 1);
			/* Restore previous data @.@ */
			tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
		}
	}
}

int arr5[4] = { 1,2,3,4 };
int trr5[4] = { 0, };

void print_trr5(int q)
{
	printf("{ ");
	while (q) { printf("%d ", trr5[--q]); }
	printf("}\n");
}

void permu(int n, int r, int q)
{
	if (r == 0) print_trr5(q);
	else
	{
		int i, tmp;
		for (i = n - 1; i >= 0; i--)
		{
			/* Swap(i, n-1): 마지막자리만 고정해서 앞부분을 다시 순열 호출 */
			tmp = arr5[i], arr5[i] = arr5[n - 1], arr5[n - 1] = tmp;
			trr5[r - 1] = arr5[n - 1];
			
			/* 일반순열 */
			permu(n - 1, r - 1, q);
			
			/* 중복순열 */
			//permu(n, r - 1, q);
			
			/* Restore previous data @.@ */
			tmp = arr5[i], arr5[i] = arr5[n - 1], arr5[n - 1] = tmp;
		}
	}
}

/////////////////////////////////////////////////////////////////
// COMBINATION::
// nCr = n! / (n-r)!* r!

static void
recurr_Combi(int n, int r)
{
	if (r == 0)
	{
		if (close_zero_val > ABS(trr[0] + trr[1]))
		{
			close_zero_val = ABS(trr[0] + trr[1]);
			mA = trr[0], mB = trr[1];
		}
	}
	else if (n < r) return;
	else
	{
		//int i, tmp;
		//for (i = n - 1; i >= 0; i--)
		//{
			trr[r - 1] = arr[n - 1];
			recurr_Combi(n - 1, r - 1);
			recurr_Combi(n - 1, r);
		//}
	}
}

int cnt;
int arr3[4] = { 1,2,3,4 };
int trr3[2] = { 0, };

void print_trr3()
{
	printf("{ %d %d }\n", trr3[0], trr3[1]);
}

void combi(int n, int r)
{
	//printf("Enter into System stack #(%d)\n", cnt++);
	// base cases
	if (r == 0)
	{
		print_trr3();
		cnt--; // Backtracking...
		return;
	}
	else if (n < r)
	{
		cnt--; // Backtracking...
		return;
	}
	// general cases
	else
	{
		/* Object code here */
		trr3[r - 1] = arr3[n - 1];
		combi(n - 1, r - 1);
		combi(n - 1, r);
	}
	cnt--; // Backtracking...
}

/////////////////////////////////////////////////////////////////
// POWER SET::
// 2^n (= 1 << n)

int data[4] = { 1, 2, 3, 4 };
int flag[4] = { 0, 0, 0, 0 };

void recurr_PwrSet(int n, int depth)
{
	if (n == depth)	
	{
		int i;
		printf("{");
		for (i = 0; i < n; i++) 
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


int main()
{
	mA = INT_MAX;
	mB = INT_MAX;
	close_zero_val = INT_MAX;

	//recurr_Permu(6, 2);
	//recurr_Combi(6, 2);
	//printf("%d %d\n", mA, mB, close_zero_val);

	//permu(4, 4, 4);
	permu(4, 2, 2);
	
	printf("\n\n");

	cnt = 1;
	combi(4, 2);

	printf("\n\n");

#if 1
	// Recursion PowerSet
	printf("Recursion Powerset:\n");
	recurr_PwrSet(sizeof(data) / sizeof(int), 0);

	printf("\n");
	// Iterative PowerSet
	printf("Iterative Powerset(Binary Counting):\n");
	static int arr2[] = { 1, 2, 3, 4 };
	static int trr[4] = { 0, };

	int i, j, k;
	int n = sizeof(arr2) / sizeof(int);

	for (i = 0; i < (1 << n); i++)
	{
		printf("{");
		for (j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				printf("%d", arr2[j]);
				trr[j] = arr2[j];
			}
			else
			{
				trr[j] = -1;
				printf(".");
			}
		}
		printf("}\n");

		printf("      -->> trr {");
		for (k = 0; k < n; k++)
		{
			printf("%d ", trr[k]);
		}
		printf("}\n");

	}

#endif
	return 0;
}
