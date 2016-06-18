#include <stdio.h>
#define SZ_S 256

char in_str[SZ_S];
char out_str[SZ_S];

static void 
clear_buf()
{
	int i;
	for (i = 0; i < SZ_S; i++)
		in_str[i] = out_str[i] = 0;
}

static void
replace_Spaces(int length)
{
	int i, new_len;
	int space_cnt = 0;
	
	for (i = 0; i < length; i++)
	{
		if (in_str[i] == ' ')
			space_cnt++;
	}

	new_len = length + space_cnt * 2;
	out_str[new_len] = '\0';

	for (i = length - 1; i >= 0; i--)
	{
		if (in_str[i] == ' ')
		{
			out_str[new_len - 1] = '0';
			out_str[new_len - 2] = '2';
			out_str[new_len - 3] = '%';
			new_len = new_len - 3;
		}
		else
		{
			out_str[new_len - 1] = in_str[i];
			new_len = new_len - 1;
		}
	}
}

int main()
{
	freopen("string_with_spaces.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i, len;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf(" %[^\n]\n", in_str);
		scanf("%d", &len);

		replace_Spaces(len);

		printf("%s\n", out_str);

		clear_buf();
	}

	return 0;
}
