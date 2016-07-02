#include <stdio.h>
#define SZ_S 1001

int keymap[10][2] = {
	{ 0, }, {0, }, // 0, 1
	{ 97, 99 }, { 100, 102 },  // 2, 3
	{ 103, 105 }, { 106, 108 },// 4, 5
	{ 109, 111 }, { 112, 115 },// 6, 7
	{ 116, 118 }, { 119, 122 } // 8, 9
};

char str[SZ_S];
int str_min, str_max;
int N;
int it_on_dic_cnt;

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_S; i++)
		str[i] = 0;
}

static void
make_min_max_val()
{
	int i = 0;

	while (str[i])
	{
		int ret;
		char s[2];
		s[0] = str[i];
		sscanf(s, "%d", &ret);

		if (ret > 1 && ret < 10)
		{
			str_min += keymap[ret][0];
			str_max += keymap[ret][1];
		}

		i++;
	}

	//printf("D1: total: min = %d, max = %d\n", str_min, str_max);
}

static void
check_it_on_dic()
{
	int i;

	for (i = 0; i < N; i++)
	{
		static char candis[SZ_S];
		scanf("%s", candis);

		int its_v = 0;
		int idx = 0;

		while (candis[idx])
		{
			its_v += candis[idx];
			idx++;
		}

		if (its_v >= str_min && its_v <= str_max)
			it_on_dic_cnt++;
	}
}

int main()
{
	freopen("keypad_inputs.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input:
		scanf("%s %d", str, &N);
		
		// solve:
		str_min = str_max = 0;
		/* MAKE min/max values of combination */
		make_min_max_val();

		it_on_dic_cnt = 0;
		/* CHECK whether it is on the scope */
		check_it_on_dic();

		// output:
		printf("%d\n", it_on_dic_cnt);

		// clear buffer:
		clear_buf();
	}

	return 0;
}
