/*
input:
6
x + 384 = 887
x +30 =200
x+30=200
x+ 5 = 2
x + 10 =20
x  +  12  = 3
========================
output:
503
170
170
-3
10
-9
*/

#include <stdio.h>
#define SZ_STR 128

char str[SZ_STR];

static void
clear_buf() 
{
	int i;

	for (i = 0; i < SZ_STR; i++)
		str[i] = 0;
}

int main() 
{
	freopen("statements.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	scanf("%d", &T);

	while (T--) 
	{
		scanf(" %[^\n]\n", str);

		int i = 0, no1 = 0, no2 = 0;
		while (str[i])
		{
			if (no1 == 0 && str[i] >= 48 && str[i] <= 57)
			{
				while (str[i] >= 48 && str[i] <= 57)
				{
					no1 = no1 * 10 + (str[i] - '0');
					i++;
				}
			}
			else if (no2 == 0 && str[i] >= 48 && str[i] <= 57)
			{
				while (str[i] >= 48 && str[i] <= 57)
				{
					no2 = no2 * 10 + (str[i] - '0');
					i++;
				}
			}

			i++;
		}

		printf("%d\n", no2 - no1);

		clear_buf();
	}

	return 0;
}
