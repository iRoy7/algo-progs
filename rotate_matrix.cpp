/*
1 2 3
4 5 6
7 8 9
-> Rotate matrix by 90 
*/
#include <stdio.h>
#define MAXIS 100
int a[MAXIS + 1][MAXIS + 1];
int T, N;
inline void printMatrix();
inline void clearMemory();
static void
helperTranspose()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = i+1; j <N; j++)
			if (i != j) {
				int tmp;
				tmp = a[i][j], a[i][j] = a[j][i], a[j][i] = tmp;
			}
}
static void
helperReverse(int *row)
{
	for (int i = 0; i < N / 2; i++) {
		int tmp;
		tmp = row[i], row[i] = row[N - i - 1], row[N - i - 1] = tmp;
	}
}
static void
rotate1()
{
	// transpose matrix
	helperTranspose();
	// reverse each row
	for (int i = 0; i < N; i++)
		helperReverse(a[i]);
}
static void
rotate2()
{
	int i, j;
	for (i = 0; i < N/2; i++)
		for (j = i; j < N - i - 1; j++) {
			int tmp = a[i][j];
			a[i][j] = a[j][N - i - 1];
			a[j][N - i - 1] = a[N - i - 1][N - j - 1];
			a[N - i - 1][N - j - 1] = a[N - j - 1][i];
			a[N - j - 1][i] = tmp;
		}
}
int main()
{
	int i, j;
	freopen("matrix_info.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	while (T--) {
		// inputs:
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				scanf("%d", &a[i][j]);
		// solve&outputs:
		printf("Rotated matrix by 90(clockwise): \n");
		rotate1();
		printMatrix();
		printf("Rotated matrix again by 90(anticlockwise): \n");
		rotate2();
		printMatrix();
		// clear memory:
		clearMemory();
	}
	return 0;
}
inline void printMatrix()
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
inline void clearMemory()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = 0;
}
