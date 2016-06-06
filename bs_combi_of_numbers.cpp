#include <stdio.h>
#define MAX 200
#define SZ_PT 6
#define MAX_D 65*SZ_PT

int DATA[MAX_D];
int ALLC[MAX_D];
int allc_idx;
unsigned int C[MAX + 1][MAX + 1] = { 0 };

static void
calcBino() {
	for (int i = 0; i <= MAX; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
}

static void
combi_util(int n, int ea, int idx, int i)
{
	if (idx == ea)
	{
		for (int i = 0; i < ea; i++)
			printf("%d ", DATA[i]);
		printf("\n");
		return;
	}

	if (i >= n+1) return;
	
	DATA[idx] = i;

	combi_util(n, ea, idx + 1, i + 1);
	combi_util(n, ea, idx, i + 1);
	
	return;
}

static void
select_pts(int n, int ea)
{
	int i;
	for (i = 0; i < MAX_D; i++)
		DATA[i] = 0;

	combi_util(n, ea, 0, 1);
	
	return;
}

int main()
{
	// generate binomial coefficient (nCr)
	calcBino();
	//printf("3's all combi = %d\n", 1 << 3);
	//printf("%d\n", C[3][0]);
	//printf("%d\n", C[3][1]);
	//printf("%d\n", C[3][2]);
	//printf("%d\n", C[3][3]);
	// generally, in case of selection
	// the number = nCr - 1 because of no selections
	// 1C0 = 2C0 = 3C0 = 4C0 ..... = nC0 = 1
	//int max_combi_cnt = (1 << SZ_PT) - 1;
	//printf("%d\n", max_combi_cnt);

	int i;
	int pt_cnt = 3;
	allc_idx = 0;

	int pt_idx = 1;
	for (i = 1; i <= pt_cnt; i++);
	{
		printf("pt_idx = %d\n", pt_idx);
		select_pts(pt_cnt, pt_idx);
		pt_idx++;
		printf("\n");
	}
	return 0;
}
