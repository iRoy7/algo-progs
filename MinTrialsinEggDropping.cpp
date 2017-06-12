/* Find minimum number of trials in worst cases */

#include <stdio.h>
const int EMAX = 101;
const int FMAX = 101;
const int IMAX = 2147483647;
inline int max(int a, int b) { return (a > b) ? a : b; }

int dropEggs(int ne, int nf)
{
	int DT[EMAX][FMAX]; // Dynamic Table
    for (int i = 0; i < EMAX*FMAX; i++)
        *((int *)DT + i) = 0;
    
    // Base Cases
	for (int e = 1; e <= ne; e++)
		DT[e][1] = 1, DT[e][0] = 0;
	for (int f = 1; f <= nf; f++)
		DT[1][f] = f;
    
    if (ne >= 2)
    {
        for (int e = 2; e <= ne; e++)
            for (int f = 2; f <= nf; f++)
            {
                DT[e][f] = IMAX;
                for (int x = 1; x <= f; x++)
                {
                    int res = 0;
                    // Two cases:
                    // (1) Breaks: The problem reduces to x-1 floors and n-1 eggs
                    // (2) Not breaks: The problem reduces to nf-x floors and n eggs
                    res = 1 + max(DT[e - 1][x - 1], DT[e][f - x]);
                    if (DT[e][f] > res)
                        DT[e][f] = res;
                }
            }
    }
    
	return DT[ne][nf];
}

int main()
{
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
        int ne, nf;
		scanf("%d %d", &ne, &nf);
		printf("\n Minimum number of trials in worst cases\n\
        	   with %d eggs %d floors is %d\n", ne, nf, dropEggs(ne, nf));
	}

	return 0;
}
