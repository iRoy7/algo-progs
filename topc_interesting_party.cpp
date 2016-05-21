// interesting party from TOPCORDER

#include <stdio.h>
#define SZ_N 50
#define SZ_STR 16

char first[SZ_STR];
char second[SZ_STR];
char n_f_tp[SZ_STR];
char n_s_tp[SZ_STR];

inline int max(int a, int b) { return (a > b) ? a : b; }

static bool
is_same(char *str1, char *str2)
{
	for (size_t i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

static void
clear_buf()
{
	for (int i = 0; i < SZ_STR; i++)
		n_f_tp[i] = n_s_tp[i] = 0;
}

int main()
{
	freopen("friends_topics.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	int T, N;
	scanf("%d", &T);

	while (T--) 
	{
		scanf("%d", &N);

		// 1th friend first topic
		scanf("%s", first);
		scanf("%s", second);

		int i, j;
		int f_tp_same_cnt = 1;
		int s_tp_same_cnt = 1;
		int ans = -2147483648;

		for (i = 1; i < N; i++)
		{
			scanf("%s", n_f_tp);
			scanf("%s", n_s_tp);

			if (is_same(n_f_tp, first))
				f_tp_same_cnt++;
			else if (is_same(n_f_tp, second))
				s_tp_same_cnt++;
			else if (is_same(n_s_tp, first))
				f_tp_same_cnt++;
			else if (is_same(n_s_tp, second))
				s_tp_same_cnt++;

			clear_buf();
		}

		ans = max(f_tp_same_cnt, ans);
		ans = max(s_tp_same_cnt, ans);

		printf("%d\n", ans);
	}

	return 0;
}
