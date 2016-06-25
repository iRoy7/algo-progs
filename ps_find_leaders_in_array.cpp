/*
An element is a leader if it is greater than
all the elements to its rightside.
The right most element is always a leader.

input
16 17 4 3 5 2
1 2 4 0
------------------
output
17 5 2
4 0
*/

#include <stdio.h>
#define SZ_N 1001

int N;
int arr[SZ_N];

// Solution1: O(N^2)
static void
print_leaders()
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] <= arr[j])
				break;			
		}

		if (j == N)
			printf("%d ", arr[i]);
	}
	printf("\n");
}

// Solution: O(N)
static void
print_leaders_opt()
{
	int i;
	int max_from_right = arr[N - 1];
	/* rightmost element is always a leader */
	printf("%d ", max_from_right);

	for (i = N - 2; i >= 0; i--)
	{
		if (arr[i] > max_from_right)
		{
			max_from_right = arr[i];
			printf("%d ", max_from_right);
		}
	}
	printf("\n");
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		// solve & output
		/* find leaders in arrays */
		print_leaders();
		printf("--------------------\n");
		print_leaders_opt();

		// clear buffer for next test cases
		for (i = 0; i < N + 1; i++)
			arr[i] = 0;
	}

	return 0;
}
