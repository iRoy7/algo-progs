#include <stdio.h>
#define SZ_S 256

char str1[SZ_S], str2[SZ_S];
char smaller[SZ_S], bigger[SZ_S];

inline int
ABS(int a) { return (a > 0) ? a : (-a); }

static void
clear_buf()
{
	int i;
	for (i = 0; i < SZ_S; i++)
		str1[i] = str2[i] = smaller[i] = bigger[i] = 0;
}

static bool
one_edit_away(char *str1, char * str2, int len1, int len2)
{
	size_t i, j;

	// check length
	if (ABS(len1 - len2) > 1) return false;

	if (len1 < len2)
	{
		for (i = 0; i < len1; i++) smaller[i] = str1[i];
		for (i = 0; i < len2; i++) bigger[i] = str2[i];
	}
	else
	{
		for (i = 0; i < len2; i++) smaller[i] = str2[i];
		for (i = 0; i < len1; i++) bigger[i] = str1[i];
	}

	size_t s_len, b_len;
	for (s_len = 0; smaller[s_len]; s_len++);
	for (b_len = 0; bigger[b_len]; b_len++);

	unsigned int h = 0, k = 0;
	bool mismatch_done = false;

	while (h < s_len && k < b_len)
	{
		if (smaller[h] != bigger[k])
		{
			if (mismatch_done)
				return false;
			mismatch_done = true;
			if (len1 == len2)
				++h;
		}
		else
		{
			++h;
		}

		++k;
	}

	return true;
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);
	
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%s %s", &str1, &str2);
		size_t len1, len2;
		for (len1 = 0; str1[len1]; len1++);
		for (len2 = 0; str2[len2]; len2++);

		bool ans = one_edit_away(str1, str2, len1, len2);

		if (ans)
			printf("Yes, Right!\n");
		else
			printf("No way T.T\n");

		clear_buf();
	}

	return 0;
}
