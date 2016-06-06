/*
input:
5
1
N
4
NNYN
NNYN
NNNN
NYYN
6
NNNNNN
YNYNNY
YNNNNY
NNNNNN
YNYNNN
YNNYNN
6
NYNNYN
NNNNNN
NNNNNN
NNYNNN
NNNNNN
NNNYYN
4
NNNN
NNNN
NNNN
NNNN
===================
outputs:
1 | 5 | 17 | 8 | 4
*/
#include <stdio.h>
#define SZ_N 51

int N;
char rel[SZ_N][SZ_N];
long long salaries[SZ_N];

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < SZ_N; i++)
	{
		salaries[i] = 0;
		for (j = 0; j < SZ_N; j++)
			rel[i][j] = 0;
	}
}

static int
get_salary(int i)
{
	if (salaries[i] == 0)
	{
		long long salary = 0;
		char *relation = rel[i];
		
		for (int j = 0; j < N; j++)
			if (relation[j] == 'Y')
				salary += get_salary(j);

		if (salary == 0) salary = 1;

		salaries[i] = salary;
	}

	return salaries[i];
}

int main()
{
	freopen("relations.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	int T, tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%s", &rel[i]);

		long long total = 0;
		for (i = 0; i < N; i++)
			total += get_salary(i);

		printf("%d\n", total);

		clear_buf();
	}

	return 0;
}
