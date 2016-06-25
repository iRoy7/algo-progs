#include <stdio.h>
#define MAX_NS 5001

int NS[MAX_NS];

static void
gen_core(int n)
{
	int no_sn = n;
	
	while (n > 0)
	{
		int k = n % 10;
		no_sn += k;
		n = n / 10;
	}

	if (!NS[no_sn] && no_sn <= MAX_NS)
		NS[no_sn]++;
}

static void
generate_SNs()
{
	int i;
	for (i = 1; i <= MAX_NS; i++)
		gen_core(i);
}

static void
print_SNs(int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		if (!NS[i])
			printf("%d ", i);
	printf("\n");
}

int main()
{
	setbuf(stdout, NULL);

	generate_SNs();
	
	int T, tc, i, a, b, sum;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &a, &b);
		print_SNs(a, b);

		sum = 0;
		for (i = a; i <= b; i++)
			if (!NS[i])
				sum += i;

		printf("%d\n", sum);
	}

	return 0;
}
