/*
input:
Tact Coa
===============
output:
1
1

(Permutations: "taco cat", "atco cta" Etc.)
*/

#include <stdio.h>
#define SZ_S 256

char str[SZ_S];

static int
get_char_index(char c)
{
	int idx = -1;
	
	if (c >= 'a' && c <= 'z') idx = c - 'a';
	else if (c >= 'A' && c <= 'Z') idx = c - 'A';
	
	return idx;
}

static bool
is_permut_of_pallindr2(const char *str)
{
	int odd_cnt = 0;
	int freq[26] = { 0, };
	int idx = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		idx = get_char_index(str[i]);

		if (idx != -1)
		{
			++freq[idx];
			
			if (freq[idx] % 2)
				++odd_cnt;
			else
				--odd_cnt;
		}
	}

	return (odd_cnt <= 1);
}

//////////////////////////////////////////////////////

inline int
toggle(int bit_vector, int idx)
{
	if (idx < 0) return bit_vector;

	int mask = 1 << idx;

	if ((bit_vector & mask) == 0)
		bit_vector |= mask;
	else
		bit_vector &= ~mask;

	return bit_vector;
}

inline bool
is_exactly_one_bit_set(int bit_vector)
{
	return ((bit_vector & (bit_vector - 1)) == 0);
}

static bool
is_permut_of_pallindr3(const char *str)
{
	int bit_vector = 0;
	int idx = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		idx = get_char_index(str[i]);
		bit_vector = toggle(bit_vector, idx);
	}

	return (bit_vector == 0 || is_exactly_one_bit_set(bit_vector));
}

int main()
{
	setbuf(stdout, NULL);
	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf(" %[\n]\n", str);

		printf("Approach2: %d\n", is_permut_of_pallindr2(str));
		printf("Approach3: %d\n", is_permut_of_pallindr3(str));

		for (i = 0; i < SZ_S; i++)
			str[i] = 0;
	}

	return 0;
}
