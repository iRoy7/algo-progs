#include <stdio.h>
#define SZN 5
#define NMAX 4

int arr[4] = { 1, 2, 3, 4 };
int Sel[SZN];

/* Combination */
// 4C3:	Combi(0, 0, 3);
// s: 0->1->2->3
// k: 1->2->3
void Combi(int s, int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < q; i++)
			printf("%d ", arr[Sel[i]]);
		printf("\n");

		return;
	}

	int i;
	for (i = s; i < NMAX; i++)
	{
		Sel[k] = i;
		Combi(i + 1, k + 1, q);
	}
}

void Combi2(int s, int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < q; i++)
			printf("%d ", arr[Sel[i]]);
		printf("\n");

		return;
	}

	int i;
	for (i = s; i < NMAX; i++)
	{
		Sel[k] = i;
		Combi2(i, k + 1, q);
	}
}

// 4C3: Combi3(4, 3, 3);
// n: 4->3->2->1
// r: 3->2->1
int trr[3] = { 0, };

void print_trr(int q)
{
	printf("{ %d %d %d }\n", trr[0], trr[1], trr[2]);
}

void Combi3(int n, int r, int q)
{
	if (r == 0)
	{
		print_trr(q);
		return;
	}
	else if (n < r)
	{
		return;
	}
	else
	{
		trr[r - 1] = arr[n - 1];
		Combi3(n - 1, r - 1, q);
		Combi3(n - 1, r, q);
	}
}

int main()
{
	printf("(1) Combi:\n");
	Combi(0, 0, 3);

	printf("(2) Dupl-Combi:\n");
	/* 중복 조합 */
	Combi2(0, 0, 4);

	printf("(3) Another-Combi: \n");
	/* Another Combi */
	Combi3(4, 3, 3);
	
	return 0;
}
