/*
From geeksforgeeks practices.
INPUT:
2
S01D01H01C01S02D02H02C02
S01S03S02S13S12S11S07D01S03S02S13D12D10D07S01
==============================================
OUTPUT:
11 11 11 11
ERROR

*/

#include <stdio.h>
#define SZ_S 1001

char str[SZ_S];
int card_types[4]; // S; 0, D:1, H:2, C:3
int s_cards[14];
int d_cards[14];
int h_cards[14];
int c_cards[14];
bool error;

static void
clear_buf()
{
	int i;

	for (i = 0; i < 4; i++)
		card_types[i] = 0;
	for (i = 0; i < 14; i++)
		s_cards[i] = d_cards[i] = h_cards[i] = c_cards[i] = 0;
	for (i = 0; i < SZ_S; i++)
		str[i] = 0;
}

static void
count_four_cards()
{
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == 'S') card_types[0]++;
		else if (str[i] == 'D') card_types[1]++;
		else if (str[i] == 'H') card_types[2]++;
		else if (str[i] == 'C') card_types[3]++;

		if (i % 3 == 1)
		{
			int ret;
			char s[2];

			s[0] = str[i];
			s[1] = str[i + 1];
			
			sscanf(s, "%d", &ret);

			if (str[i - 1] == 'S')
			{
				s_cards[ret]++;
				if (s_cards[ret] > 1)
					error = true;
			}
			else if (str[i - 1] == 'D')
			{
				d_cards[ret]++;
				if (d_cards[ret] > 1)
					error = true;
			}
			else if (str[i - 1] == 'H')
			{
				h_cards[ret]++;
				if (d_cards[ret] > 1)
					error = true;
			}
			else if (str[i - 1] == 'C')
			{
				c_cards[ret]++;
				if (c_cards[ret] > 1)
					error = true;
			}
		}
	}
}

int main()
{
	freopen("four_cards.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		// input:
		scanf("%s", str);

		// solve:
		error = false;
		count_four_cards();

		// output:
		if (error)
			printf("ERROR\n");
		else
		{
			for (i = 0; i < 4; i++)
				printf("%d ", 13 - card_types[i]);
			printf("\n");
		}

		// clear:
		clear_buf();
	}

	return 0;
}
