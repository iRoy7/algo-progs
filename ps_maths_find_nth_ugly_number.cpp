/*
input:
10
4
68
=========
output:
12
4
512
*/

#include <stdio.h>

static int
max_divide(int a, int b)
{
	// 나눠질 때까지 나누고,
	// 남은 값 return
	while (a%b == 0)
		a = a / b;
	return a;
}

static bool
is_ugly(int no)
{
	no = max_divide(no, 2);
	no = max_divide(no, 3);
	no = max_divide(no, 5);

	return (no == 1);
}

static unsigned
get_nth_ugly_num(int n)
{
	int i = 1;
	int cnt = 1;

	while (n > cnt)
	{
		i++;
		if (is_ugly(i))
			cnt++;
	}

	return i;
}


int main()
{
	setbuf(stdout, NULL);

	int T, tc, N;
	unsigned no;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		no = 0;
		no = get_nth_ugly_num(N);
		printf("%d\n", no);
	}

	return 0;
}
