// Find the palindrome length from TOPCORDER
// aabbcc|_|

#include <stdio.h>
#define SZ_STR 110

static int
find_palindr_length(char *str, int len)
{
	int i;
	int p_len = len;
	int bl = len; // bl: base line
	bool first = true;

	for (i = 0; (i <= bl) && (i < len); i++)
	{
		if (first && str[i] != str[bl])
		{
			bl -= 1;
			i -= 1;
			first = false;
			continue;
		}
		if (str[i] != str[bl])
		{
			//printf("D2: i = %d, bl = %d\n", i, bl);
			p_len += 1;
		}
		else
		{
			bl -= 1;
		}
	}

	return p_len;
}

static void
clear_buf(char *str)
{
	for (int i = 0; i < SZ_STR; i++)
		str[i] = 0;
}

int main()
{
	int T;
	static char INSTR[SZ_STR];

	setbuf(stdout, NULL);
	scanf("%d", &T);

	while (T--) {
		// inputs
		scanf("%s", INSTR);
		
		size_t cur_len;
		for (cur_len = 0; INSTR[cur_len]; cur_len++);
		
		// find the length of palindrome
		size_t len = 0;
		len = find_palindr_length(INSTR, cur_len);

		// outputs
		printf("%d\n", len);
		
		// clear buffer
		clear_buf(INSTR);
	}
	return 0;
}
