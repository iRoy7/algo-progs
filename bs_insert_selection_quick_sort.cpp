#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define NSZ 500

int arr[NSZ];

static void
insertion_sort(int nSize)
{
	int i, j, tmp;

	for (i = 1; i < nSize; i++)
	{
		tmp = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = tmp;
	}
}

static void
selection_sort(int nSize)
{
	int i, j, min, tmp;
	for (i = 0; i < nSize - 1; i++)
	{
		min = i;
		for (j = i + 1; j < nSize - 1; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		tmp = arr[i], arr[i] = arr[min], arr[min] = tmp;
	}
}

static void
q_sort(int s, int e)
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
	q_sort(s, l - 1);
	q_sort(r + 1, e);
}

int main()
{
	int N, i;

	time_t timer = time(0);
	srand(static_cast<unsigned>(timer));

	printf("Enter a number between 1 and %d : ", NSZ);

	scanf("%d", &N);

	assert(!(N > NSZ), "Out of scope!");

	printf("Buidling an array of %d integers\n", N);

	for (i = 0; i < N; i++)
		arr[i] = rand() % NSZ;

	printf("Before sorting: \n");

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");

	/* Quick sort */
	if (N > 50)
	{
		printf("QUICK: if (N > 50)\n");
		q_sort(0, N);
	}
	/* Insertion sort */
	else if (N < 10)
	{
		printf("INSERTION: if (N < 20)\n");
		insertion_sort(N);
	}
	else
	{
		printf("SELECTION: if (10 < N < 50)\n");
		selection_sort(N);
	}

	printf("AFter sorting: \n");

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
