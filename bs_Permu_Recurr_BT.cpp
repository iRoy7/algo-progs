#include <stdio.h>
#define NMAX 5
#define CMAX 4

int arr[NMAX] = { 1, 2, 3, 4 };

int trr[10];
int recurr_cnt;
void print_trr(int q)
{
	while (q)
	{
		printf("%d ", trr[--q]);
	}
	printf("\n");
}

void recurr_Permu(int n, int r, int q)
{
	// base cases:
	if (r == 0)
	{
		recurr_cnt++;
		print_trr(q);
	}
	else
	{
		int i, tmp;
		for (i = n - 1; i >= 0; i--)
		{
			tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
			trr[r - 1] = arr[n - 1];
			recurr_Permu(n - 1, r - 1, q);
			/* Restore previous data @.@ */
			tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
		}
	}
}

int sys_st_cnt;
int cnt;

void print_process_solution(int a[], int k)
{
	int i;
	for (i = 1; i <= k; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void BT(int a[], int k, int input)
{
	sys_st_cnt++;
	int c[CMAX] = { 0, };
	int nCands = 0;
	int inPerm[NMAX] = { 0, };
	int i;

	/* nPr = 4P3: k == input - 1*/
	/* nPn = 4P4: k == input */
	if (k == input - 2)
	{
		cnt++;
		print_process_solution(a, k);
		sys_st_cnt--;
		return;
	}
	else
	{
		k++;
		/*construct candidates*/
		for (i = 0; i < k; i++)
			inPerm[a[i]] = 1;

		for (i = 1; i <= input; i++)
		{
			if (inPerm[i] == 0)
				c[nCands++] = i;
		}

		for (i = 0; i < nCands; i++)
		{
			a[k] = c[i];
			BT(a, k, input);
		}
	}
	sys_st_cnt--;
}

int main()
{
	// Permutation
	/* Recursive Permutation */
	recurr_cnt = 0;
	recurr_Permu(4, 2, 2);
	printf("nPr = 4P3 = 4*3*2 = %d\n", recurr_cnt);

	/* Backtracking */
	int a[CMAX + 1] = { 0, };
	cnt = 0;
	sys_st_cnt = 0;
	BT(a, 0, 4);
	printf("nPr = %d\n", cnt);

	return 0;
}
