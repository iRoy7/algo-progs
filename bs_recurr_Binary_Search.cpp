#include <stdio.h>

int arr[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 19 };

int recurr_bin_search(int l, int r, int key)
{
	if (l > r) return false;
	
	int mid = (l + r) / 2;
	if (key == arr[mid]) return true;
	else if (key < arr[mid])
	{// decrease right
		recurr_bin_search(l, mid - 1, key);
	}
	else if (key > arr[mid])
	{// increase left
		recurr_bin_search(mid + 1, r, key);
	}
}

int main()
{
	int T, tc;
	
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		int n = sizeof(arr) / sizeof(int);

		if (recurr_bin_search(0, n-1, 5))
			printf("found\n");
		else
			printf("Not here\n");
	}

	return 0;
}
