/*
Need to be optimized
*/

#include <stdio.h>
#define SZ_S 1001

struct RLE {
	char ch;
	int len;
};

struct RLE a[SZ_S], b[SZ_S], c[SZ_S];
int a_cnt, b_cnt, c_cnt;
int matched_cnt;
bool no_match;
int ed_idx;

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_S; i++)
	{
		a[i].ch = b[i].ch = c[i].ch = 0;
		a[i].len = b[i].len = c[i].len = 0;
	}
}

static void
print_target_words(int a_cnt, int b_cnt, int c_cnt)
{
	int i;

	for (i = 0; i < a_cnt; i++)
		printf("%c%d ", a[i].ch, a[i].len);
	printf("\n");
	for (i = 0; i < b_cnt; i++)
		printf("%c%d ", b[i].ch, b[i].len);
	printf("\n");
	for (i = 0; i < c_cnt; i++)
		printf("%c%d ", c[i].ch, c[i].len);
	printf("\n");
}

static void
input_target_words()
{
	int abc_cnt = 0;

	// input
	do {
		char x;
		int l;
		struct RLE tmp;

		scanf(" %c", &x);
		if (x == '$')
		{
			abc_cnt++;
			if (abc_cnt != 3) continue;
			else break;
		}
		else
		{
			scanf("%d", &l);
			if (abc_cnt == 0)
			{
				tmp.ch = x, tmp.len = l;
				a[a_cnt++] = tmp;
			}
			else if (abc_cnt == 1)
			{
				tmp.ch = x, tmp.len = l;
				b[b_cnt++] = tmp;
			}
			else
			{
				tmp.ch = x, tmp.len = l;
				c[c_cnt++] = tmp;
			}
		}
	} while (1);
}

static void
check_matched()
{
	int i, j, k;
	int nx = 0;
	
	for (i = 0; i < b_cnt; i++)
	{
		for (j = nx; j < a_cnt; j++)
		{
			if (b[i].ch == a[j].ch)
			{
				if (a[j].len >= b[i].len)
				{
					a[j].len = a[j].len - b[i].len;
					//if (st_idx == -1)
					//st_idx = j;
					nx = j + 1;
					ed_idx = j;
					matched_cnt++;
					break;
				}
			}

			if (matched_cnt > 0 && matched_cnt < b_cnt)
			{
				no_match = true;
				break;
			}
		}

		if (no_match) break;
	}

}

static void
print_outputs()
{
	int i, j, k;

	if (no_match || (matched_cnt < b_cnt))
	{
		// just print A only
		for (i = 0; i < a_cnt; i++)
			printf("%c %d ", a[i].ch, a[i].len);
	}
	else if (matched_cnt == b_cnt)
	{
		// replace with C from st_idx to ed_idx
		int cnt = 0;
		bool rep_flag = false;
		struct RLE replaced[SZ_S];

		for (i = 0; i < a_cnt; i++)
		{
			if (a[i].len == 0 && !rep_flag)
			{
				//printf("->> D1:\n");

				for (j = 0; j < c_cnt; j++)
				{
					if (replaced[cnt - 1].ch == c[j].ch)
						replaced[cnt - 1].len += c[j].len;
					else
						replaced[cnt++] = c[j];
				}

				rep_flag = true;
			}
			else
			{
				if (ed_idx > -1 && i == ed_idx)
				{
					if (!rep_flag)
					{
						for (j = 0; j < c_cnt; j++)
						{
							//printf("->>>>> D4:\n");
							if (replaced[cnt - 1].ch == c[j].ch)
								replaced[cnt - 1].len += c[j].len;
							else
								replaced[cnt++] = c[j];
						}
					}

					//printf("->>> D2:\n");
					if (replaced[cnt - 1].ch == a[i].ch)
						replaced[cnt - 1].len += a[i].len;
					else
						replaced[cnt++] = a[i];
				}
				else if (a[i].len == 0)
				{
					// do nothing
				}
				else
				{
					//printf("->>>> D3:\n");
					replaced[cnt++] = a[i];
				}
			}
		}

		for (k = 0; k < cnt; k++)
			printf("%c %d ", replaced[k].ch, replaced[k].len);
	}

	printf("$\n");
}

int main()
{
	freopen("double_encodings.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, j, k;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input:
		a_cnt = 0, b_cnt = 0, c_cnt = 0;

		input_target_words();
		//print_target_words(a_cnt, b_cnt, c_cnt);

		// solve:
		matched_cnt = 0;
		no_match = false;
		ed_idx = -1;

		/* check matched with B and C*/
		check_matched();
		//print_target_words(a_cnt, b_cnt, c_cnt);

		// output:
		print_outputs();

		// clear buf:
		clear_buf();
	}

	return 0;
}
