#include <stdio.h>
#define NMAX 3

int Src[NMAX] = { 1, 2, 3 };
int Sel[NMAX];
int P;
int cnt;

void PermutR_DFS(int k, int q, int prevSum)
{
	if (k == q)
	{
		if (prevSum == P) cnt++;
		return;
	}
	if (prevSum == P)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < NMAX; i++)
	{
		//Sel[k] = i;
		int selVal = Src[i];
		int curSum = prevSum + selVal;
		
		PermutR_DFS(k + 1, q, curSum);
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &P);

		cnt = 0;		
		PermutR_DFS(0, 10, 0);
		printf("%d\n", cnt);
	}

	return 0;
}
