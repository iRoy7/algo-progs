#include <stdio.h>

void print_process_solution(char a[], int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n");
}

void print_process_solution(int a[], int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

template <typename T>
void swap(T a[], int i, int j)
{
	T tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

template <typename T>
int permu(T a[], int n, int r, int depth)
{
	int cnt = 0;

	if (depth == r)
	{
		print_process_solution(a, r);
		return 1;
	}
	else
	{
		for (int i = depth; i < n; i++)
		{
			swap(a, i, depth);
			cnt += permu(a, n, r, depth + 1);
			swap(a, i, depth);
		}
	}

	return cnt;
}

int main()
{
	int int_arr[3] = { 3, 6, 9 };
	char ch_arr[4] = { 'A', 'B', 'C', 'D' };

	printf("%dP%d cnt: %d\n", 3, 2, permu(int_arr, 3, 2, 0));
	printf("%dP%d cnt: %d\n", 4, 3, permu(ch_arr, 4, 4, 0));

	return 0;
}
