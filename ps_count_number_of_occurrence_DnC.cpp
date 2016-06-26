/*
Solution 1: O(N)
Solution 2: O(Logn)
*/

#include <stdio.h>
#include <time.h>
#define SZ_N 100001

int N, X;
int arr[SZ_N];

static void
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = arr[(s + e) / 2];
	while (1)
	{
		while (arr[++l] < p);
		while (arr[--r] > p);
		if (l >= r) break;
		tmp = arr[l], arr[l] = arr[r], arr[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static int
count_num_occurr()
{
	int i, cnt = 0;

	for (i = 0; i < N; i++)
	{
		if (arr[i] == X) cnt++;
		if (arr[i] > X) break;
	}

	return cnt;
}

static int
first(int low, int high)
{
	if (high >= low)
	{
		int mid = (low + high) / 2;

		if ((mid == 0 || X > arr[mid - 1])
			&& arr[mid] == X)
			return mid;
		else if (X > arr[mid])
			return first((mid + 1), high);
		else
			return first(low, (mid - 1));
	}

	return -1;
}

static int
last(int low, int high)
{
	if (high >= low)
	{
		int mid = (low + high) / 2;

		if ((mid == N - 1 || X < arr[mid + 1])
			&& arr[mid] == X)
			return mid;
		else if (X < arr[mid])
			return last(low, (mid - 1));
		else
			return last((mid + 1), high);
	}

	return -1;
}

static int 
count_num_occurr2()
{
	int i; // index of first occurrence of x
	int j; // index of last occurrence of x

	i = first(0, N - 1);

	if (i == -1) return i;

	j = last(i, N - 1);

	return j - i + 1;
}

int main()
{
	freopen("numbers_of_occurrence.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, num_occur;
	clock_t start_p, end_p;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &X);
		for (i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		qsort(0, N - 1);

		num_occur = -1;
		
		// Solution 1
		start_p = clock();
		num_occur = count_num_occurr();

		if (num_occur > 0)
			printf("(S1) %d\n", num_occur);
		else
			printf("(S1) -1\n");
		end_p = clock();

		printf("(S1) Speed = %.11f\n", (double)(end_p - start_p) / CLOCKS_PER_SEC);
		
		printf("_______________________________________\n");

		// Solution 2
		start_p = clock();
		num_occur = count_num_occurr2();
		
		if (num_occur > 0)
			printf("(S2) %d\n", num_occur);
		else
			printf("(S2) -1\n");
		end_p = clock();

		printf("(S2) Speed = %.11f\n", (double)(end_p - start_p) / CLOCKS_PER_SEC);

		printf("========================================\n\n");

		for (i = 0; i < SZ_N; i++)
			arr[i] = 0;
	}

	return 0;
}
