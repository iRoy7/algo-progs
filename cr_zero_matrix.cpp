/* 
2
3 4
1 5 6 0
0 7 9 3
4 0 5 3
3 4
1 5 6 0
1 7 9 3
4 1 0 3
*/
#include <stdio.h>
#define MAXIS 100
int T, N, M;
int a[MAXIS + 1][MAXIS + 1];

static void 
clearMemory()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			a[i][j] = 0;
}

static void 
printMatrix()
{
	int i, j; 
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

static void 
nullifyRow(int row)
{
	for (int j = 0; j < M; j++)
		a[row][j] = 0;
}
static void 
nullifyCol(int col)
{
	for (int i = 0; i < N; i++)
		a[i][col] = 0;
}
static void 
nullifyMatrix()
{
	int i, j;
	bool firstRow = false;
	bool firstCol = false;

	// first row
	for (i = 0; i < M; i++)
		if (a[0][i] == 0) {
			firstRow = true;
			break;
		}
	// first col
	for (i = 0; i < N; i++)
		if (a[i][0] == 0) {
			firstCol = true;
			break;
		}
	// rest of the matrix
	for (i = 1; i < N; i++)
		for (j = 1; j< M; j++)
			if (a[i][j] == 0) {
				a[i][0] = 0;
				a[0][j] = 0;
			}
	printf("D1:\n");
	printMatrix();
	// now we know which row and column to be nullify using information stored in previous step.
	// row first
	for (i = 1; i < N; i++)
		if (a[i][0] == 0)
			nullifyRow(i);
	// cols now
	for (j = 1; j < M; j++)
		if (a[0][j] == 0)
			nullifyCol(j);
	printf("D2:\n");
	printMatrix();
	// now first row:
	if (firstRow) nullifyRow(0);
	// now rist col:
	if (firstCol) nullifyCol(0);
}

int main()
{
	freopen("random_matrixes.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	int T, i, j;
	scanf("%d", &T);
	
	while (T--) {
		// inputs:
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf("%d", &a[i][j]);
		printf("Matrix Before: \n");
		printMatrix();
		// solve & outputs:
		nullifyMatrix();
		printf("Matrix After: \n");
		printMatrix();
		// clear memory:
		clearMemory();
	}
	
	return 0;
}
