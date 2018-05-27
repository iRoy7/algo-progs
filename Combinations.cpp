#include <stdio.h>
const int NMAX = 4;

int SRC[NMAX] = { 1, 2, 3, 4 };
int SEL[NMAX];

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
			printf("%d ", SRC[SEL[i]]);
		printf("\n");

		return;
	}

	for (int i = s; i < NMAX; i++)
	{
		SEL[k] = i;
		Combi_Set_L(i + 1, k + 1, q);
	}
}

/* Combination with Repetition */
/* Lexicographic order */
void RCombi_Set_L(int s, int k, int q)
{
	if (k == q)
	{
		for (int i = 0; i < q; i++)
			printf("%d ", SRC[SEL[i]]);
		printf("\n");

		return;
	}

	for (int i = s; i < NMAX; i++)
	{
		SEL[k] = i;
		RCombi_Set_L(i, k + 1, q); /* 중복조합은 i가 증가하지 않음 */
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

void Combi_Set_Anti_L(int n, int r, int q)
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
		trr[r - 1] = SRC[n - 1]; /* 뒤에서부터 선택 */
		Combi_Set_Anti_L(n - 1, r - 1, q);
		Combi_Set_Anti_L(n - 1, r, q);
	}
}

void SEL_init(void)
{
	for (int i = 0; i < NMAX; i++) SEL[i] = 0;
}

int main()
{
	printf("Source Array: \n [ %d | %d | %d | %d ] \n", SRC[0], SRC[1], SRC[2], SRC[3]);

	/* Combination */
	/* Lexicographic order */
	printf("(1) L order Combination (4C3):\n");
	Combi_Set_L(0, 0, 3);

	SEL_init();

	/* Combination with Repetition */
	/* Lexicographic order */
	printf("(2) L order Combination R (4C3):\n");
	RCombi_Set_L(0, 0, 3);

	/* 역순 출력*/
	printf("(3) Anti-L order Combination (4C3): \n");
	Combi_Set_Anti_L(4, 3, 3);

	return 0;
}
