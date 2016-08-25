#include <stdio.h>
#define SZN 4
#define NMAX 3

int Src[SZN] = { 3, 6, 9 };
int Sel[SZN];
int V[SZN];

/* Permutation */
/* Lexicographic order */
// 3P3: Permut(0);
// k: 1->2->3
void Permut_Set(int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", Src[Sel[i]-1]);
			//printf("%d ", Sel[i]);
		printf("\n");
		
		return;
	}

	for (int i = 1; i <= NMAX; i++)
	{
		if (V[i] == 0)
		{
			V[i] = 1; 
			Sel[k] = i;
			
			//Sel[k] = Src[i-1];
			Permut_Set(k + 1, q);
			
			V[i] = 0;
		}
	}
}

/* Permutation with Repetition */
/* Lexicographic order */
void PermutR_Set(int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", Src[Sel[i] - 1]);
		printf("\n");

		return;
	}

	for (int i = 1; i <= NMAX; i++)
	{
		Sel[k] = i;
		PermutR_Set(k + 1, q);
	}
}

/* Permutation */
/* Anti-Lexicographic Order */
// 3P3: Permut3(3, 3, 3);
// n: 3->2->1;
// r: 3->2->1;
int trr[3] = { 0, };

void print_trr(int q)
{
	while (q) { printf("%d ", trr[--q]); }
	printf("\n");
}

void Permut_Set_AL(int n, int r, int q)
{
	if (r == 0)
	{
		print_trr(q);
		return;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int tmp;
		tmp = Src[i], Src[i] = Src[n - 1], Src[n - 1] = tmp; /* 뒤에서부터 선택 */
		
		trr[r - 1] = Src[n - 1];
		Permut_Set_AL(n - 1, r - 1, q);
		
		tmp = Src[i], Src[i] = Src[n - 1], Src[n - 1] = tmp;
	}
}

int main()
{
	printf("(1) L order Permutation (3P3):\n");
	Permut_Set(0, 3);

	printf("(2) L order Permutation R(3P3):\n");
	PermutR_Set(0, 3);

	printf("(3) Anti-L order Permutation(3P3): \n");
	Permut_Set_AL(3, 3, 3);

	return 0;
}
