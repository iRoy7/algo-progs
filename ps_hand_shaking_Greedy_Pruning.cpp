/*
INPUT:
2
8
90 80 40 25 35 50 60 75
13
90 80 40 25 35 50 60 75 30 15 70 110 130
=========================================
OUTPUT:
29650
65125

*/

#include <stdio.h>
#define SZ_N 21

int N;
int MW[SZ_N];	// metro weight
int check[SZ_N];
int max_v;		// maximum validity

inline int
max(int a, int b) { return (a > b) ? a : b; }

static void
clear_Buf()
{
	int i;
	for (i = 0; i <= SZ_N; i++)
		MW[i] = check[i] = 0;
}

static void
print_Weightings()
{
	int i;
	for (i = 1; i <= N; i++)
		printf("%d ", MW[i]);
	printf("\n");
}

static bool
is_Done()
{
	int i;
	for (i = 1; i <= N; i++)
		if (!check[i])
			return false;
	return true;
}

static void
calc_Validity(int f1, int t1, int f2, int t2)
{
	int con1 = (MW[f1] + MW[t1])*(MW[f1] + MW[t1]);
	int con2 = (MW[f2] + MW[t2])*(MW[f2] + MW[t2]);
	max_v = max(max_v, (con1 + con2));

	//printf("-> %d\n", max_v);
}

static void
check_Validity(int idx)
{
	// check the idx of each nodes
	check[idx] = 1;
	int f1, t1, f2, t2;

	f1 = 1;

	int i, j, k;

	for (i = 3; i <= N-1; i++) /// 1st to
	{
		// 1st connection: f1 -> t1
		t1 = i;

		if (i < 6)
		{
			// Outer
			for (j = i + 2; j <= N - 1; j++) /// 2nd from
			{
				f2 = j;

				for (k = j + 2; k <= N - 1; k++) /// 2nd to
				{
					// 2nd connection: f2 -> t2
					t2 = k;

					/* calculate Validity */
					calc_Validity(f1, t1, f2, t2);
				}
			}
		}
		else
		{
			// *** Inner
			for (j = 3; j < t1-2; j++) /// 2nd from
			{
				f2 = j;

				for (k = j + 2; k < t1 - 1; k++) // 2nd to
				{
					t2 = k;

					/* calculate Validity */
					calc_Validity(f1, t1, f2, t2);
				}
			}

			if (i < N - 4)
			{
				// Outer
				for (j = i + 2; j <= N - 1; j++) /// 2nd from
				{
					f2 = j;

					for (k = j + 2; k <= N - 1; k++) /// 2nd to
					{
						// 2nd connection: f2 -> t2
						t2 = k;

						/* calculate Validity */
						calc_Validity(f1, t1, f2, t2);
					}
				}
			}
		}
	}
}

static void
shift_Weightings()
{
	int i, tmp = MW[1];
	for (i = 1; i < N; i++)
		MW[i] = MW[i + 1];
	MW[N] = tmp;
}

int main()
{
	freopen("metro_weightings.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);
	
	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			scanf("%d", &MW[i]);

		// solve
		max_v = -2147483648;
		int idx = 1;
		/* check current weighting from 1 */
		check_Validity(idx);

		//print_Weightings();
#if 1
		while (!is_Done())
		{
			/* shift right */
			shift_Weightings();

			//print_Weightings();
			idx++;

			/* check weighting from 1 after shifting */
			check_Validity(idx);
		}
#endif

		// output
		printf("%d\n", max_v);

		// clear
		clear_Buf();		
	}

	return 0;
}
