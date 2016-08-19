#include <stdio.h>
#define SZN 4
#define NMAX 3

int arr[SZN] = { 3, 6, 9 };
int Sel[SZN];
int V[SZN];

/* Permutation */
// 3P3: Permut(0);
// k: 1->2->3
void Permut(int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", arr[Sel[i]-1]);
			//printf("%d ", Sel[i]);
		printf("\n");
		
		return;
	}

	int i;
	for (i = 1; i <= NMAX; i++)
	{
		if (V[i] == 0)
		{
			V[i] = 1; 
			Sel[k] = i;
			//Sel[k] = arr[i-1];
			Permut(k + 1, q);
			V[i] = 0;
		}
	}
}

/* 중복 순열*/
void Permut2(int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", arr[Sel[i] - 1]);
		printf("\n");

		return;
	}

	int i; 
	for (i = 1; i <= NMAX; i++)
	{
		Sel[k] = i;
		Permut2(k + 1, q);
	}
}

// 3P3: Permut3(3, 3, 3);
// n: 3->2->1;
// r: 3->2->1;
int trr[3] = { 0, };

void print_trr(int q)
{
	while (q) { printf("%d ", trr[--q]); }
	printf("\n");
}

void Permut3(int n, int r, int q)
{
	if (r == 0)
	{
		print_trr(q);
		return;
	}

	int i;
	for (i = n - 1; i >= 0; i--)
	{
		int tmp;
		tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
		trr[r - 1] = arr[n - 1];
		Permut3(n - 1, r - 1, q);
		tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
	}
}

int main()
{
	printf("(1) Permut:\n");
	Permut(0, 3);

	printf("(2) Dupl-Permut:\n");
	Permut2(0, 3);

	printf("(3) Another-Permut: \n");
	Permut3(3, 3, 3);

	return 0;
}
