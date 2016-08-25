#include <stdio.h>
#define NMAX 5
#define CMAX 4

int Src[NMAX] = { 1, 3, 6, 9 };
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

/* Anti-Lexicographic Order */
void recurr_Permut(int n, int r, int q)
{
	// base cases:
	if (r == 0)
	{
		recurr_cnt++;
		print_trr(q);
	}
	else
	{
		int tmp;
		for (int i = n - 1; i >= 0; i--)
		{
			tmp = Src[i], Src[i] = Src[n - 1], Src[n - 1] = tmp;
			
			trr[r - 1] = Src[n - 1];
			recurr_Permut(n - 1, r - 1, q);

			/* Restore previous data @.@ */
			tmp = Src[i], Src[i] = Src[n - 1], Src[n - 1] = tmp;
		}
	}
}

int sys_st_cnt;
int cnt;

void print_process_solution(int a[], int k)
{
	for (int i = 1; i <= k; i++)
		printf("%d ", Src[a[i]-1]);
	printf("\n");
}

/* Lexicographic Order */
void BACKTRACKING(int a[], int k, int r, int input)
{
	sys_st_cnt++;

	int c[CMAX] = { 0, };
	int nCands = 0;
	int inPerm[NMAX] = { 0, };

	if (k == r)
	{
		cnt++;
		print_process_solution(a, k);
		sys_st_cnt--;
		return;
	}
	else
	{
		k++;

		int i;
		/* construct candidates */
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
			BACKTRACKING(a, k, r, input);
		}
	}
	sys_st_cnt--;
}

int main()
{
	// Permutation
	/* Recursive Permutation */
	/* Anti-Lexicographic Order */
	recurr_cnt = 0;
	recurr_Permut(4, 3, 3);
	printf("nPr = 4P3 = 4*3*2 = %d\n", recurr_cnt);

	/* BACKTRACKING */
	/* Lexicographic Order */
	int a[CMAX + 1] = { 0, };
	cnt = 0;
	sys_st_cnt = 0;
	BACKTRACKING(a, 0, 3, 4);
	printf("nPr = %d\n", cnt);

	return 0;
}
