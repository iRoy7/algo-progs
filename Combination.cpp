#include <stdio.h>
#define SZN 5
#define NMAX 4

int Src[SZN] = { 1, 2, 3, 4 };
int Sel[SZN];

/* Combination */
/* Lexicographic order */
// 4C3:	Combi_Set_L(0, 0, 3);
// s: 0->1->2->3
// k: 0->1->2
void Combi_Set_L(int s, int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");

		return;
	}

	int i;
	for (i = s; i < NMAX; i++)
	{
		Sel[k] = i;
		Combi_Set_L(i + 1, k + 1, q);
	}
}

/* Combination with Repetition */
/* Lexicographic order */
void CombiR_Set_L(int s, int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");

		return;
	}

	int i;
	for (i = s; i < NMAX; i++)
	{
		Sel[k] = i;
		CombiR_Set_L(i, k + 1, q); /* 중복조합은 i가 증가하지 않음 */
	}
}

/* Combination */
/* Anti-Lexicographic order */
// 4C3: Combi3(4, 3, 3);
// n: 4->3->2->1
// r: 3->2->1
int trr[3] = { 0, };

void print_trr(int q)
{
	printf("{ %d %d %d }\n", trr[0], trr[1], trr[2]);
}

void Combi_Set_AL(int n, int r, int q)
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
		trr[r - 1] = Src[n - 1]; /* 뒤에서부터 선택 */
		Combi_Set_AL(n - 1, r - 1, q);
		Combi_Set_AL(n - 1, r, q);
	}
}

int main()
{
	printf("Source Array: \n [ %d | %d | %d | %d ] \n", Src[0], Src[1], Src[2], Src[3]);

	/* Combination */
	/* Lexicographic order */
	printf("(1) L order Combination (4C3):\n");
	Combi_Set_L(0, 0, 3);

	for (int i = 0; i < SZN; i++) Sel[i] = 0;

	/* Combination with Repetition */
	/* Lexicographic order */
	printf("(2) L order Combination R (4C3):\n");
	CombiR_Set_L(0, 0, 3);

	/* 역순 출력*/
	printf("(3) Anti-L order Combination (4C3): \n");
	Combi_Set_AL(4, 3, 3);
	
	return 0;
}
