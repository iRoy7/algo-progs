#include <stdio.h>
#define MAXIS 20

int n, key;
int a[MAXIS + 1];

static int 
seqsearch(int n, int x)
{
	int location;
	location = 1;

	while (location <= n && a[location] != x)
		location++;

	if (location > n) location = 0;
	return location;
}

static int 
sum()
{
	int total = 0;
	for (int i = 1; i <= n; i++)
		total += a[i];
	return total;
}

static void 
qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = a[(s + e) / 2];
	while (1) {
		while (a[++l] < p);
		while (a[--r] > p);
		if (l >= r) break;
		tmp = a[l], a[l] = a[r], a[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

static int 
binsearch(int n, int x)
{
	int location, low, high, mid;
	low = 1, high = n;
	location = 0;
	
	while (low <= high && location == 0) {
		mid = (low + high) / 2;
		if (x == a[mid])
			location = mid;
		else if (x < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return location;
}

static int 
location_recursion(int low, int high)
{
	int mid;
	if (low > high)
		return 0;
	else {
		mid = (low + high) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return location_recursion(low, mid - 1);
		else
			return location_recursion(mid + 1, high);
	}
}

int main()
{
	freopen("basic_inputs.txt", "r", stdin);
	setbuf(stdout, NULL);
	// inputs:
	scanf("%d %d", &n, &key);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		
	printf("Input items:\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");

	// solve 1: find a key via sequential search
	int ret1 = seqsearch(n, key);
	printf("1.find a key = %d\n", ret1);

	// solve 2: sum of items
	int ret2 = sum();
	printf("2.sum of items = %d\n", ret2);

	// solve: qsort
	qsort(1, n);
	
	printf("Sorted items:\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");

	// solve 3: find a key via binary search
	int ret3 = binsearch(n, key);
	printf("3.find a key = %d\n", ret3);

	// solve 4: find a key via binary search based on recursion
	int ret4 = location_recursion(1, n);
	printf("4.find a key = %d\n", ret4);
	
	return 0;
}
