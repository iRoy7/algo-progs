#include <stdio.h>
#define INT_MAX 2147483647
#define ABS(a) (((a) < (0))?-(a):(a))

int arr[7] = { 1, 60, -10, 70, -80, 85 };
int trr[7] = { 0, };
int mA, mB;
int close_zero_val;

static void
recurr_Permu(int n, int r)
{
	if (r == 0)
	{
		if (close_zero_val > ABS(trr[0] + trr[1]))
		{
			close_zero_val = ABS(trr[0] + trr[1]);
			mA = trr[0], mB = trr[1];
		}
	}
	else
	{
		int i, tmp;
		for (i = n - 1; i >= 0; i--)
		{
			tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
			trr[r - 1] = arr[n - 1];
			recurr_Permu(n - 1, r - 1);
			/* Restore previous data @.@ */
			tmp = arr[i], arr[i] = arr[n - 1], arr[n - 1] = tmp;
		}
	}
}

static void
recurr_Combi(int n, int r)
{
	if (r == 0)
	{
		if (close_zero_val > ABS(trr[0] + trr[1]))
		{
			close_zero_val = ABS(trr[0] + trr[1]);
			mA = trr[0], mB = trr[1];
		}
	}
	else
	{
		int i, tmp;
		for (i = n - 1; i >= 0; i--)
		{
			trr[r - 1] = arr[n - 1];
			recurr_Combi(n - 1, r - 1);
			recurr_Combi(n - 1, r);
		}
	}
}

int main()
{
	mA = INT_MAX;
	mB = INT_MAX;
	close_zero_val = INT_MAX;

	recurr_Permu(6, 2);
	recurr_Combi(6, 2);

	printf("%d %d\n", mA, mB, close_zero_val);
	
	return 0;
}
