// Number Magic(P173) from TOPCODER
// inputs:
// YNYY
// YNNN
// NNNN
// NYNY
//====================
// outputs:
// 5 | 8 | 16 | 1 | 11

#include <stdio.h>

char cards[16][5] = { 
	"YYYY",
	"YYYN",
	"YYNY",
	"YYNN",
	"YNYY",
	"YNYN",
	"YNNY",
	"YNNN",
	"NYYY",
	"NYYN",
	"NYNY",
	"NYNN",
	"NNYY",
	"NNYN",
	"NNNY",
	"NNNN"
};

static bool
is_same(char *str, char *ans)
{
	for (int i = 0; i < 4; i++)
	{
		if (str[i] != ans[i])
			return false;
	}
	return true;
}

int main()
{
	freopen("magic_card_answers.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	int T, i;
	static char answers[5];
	scanf("%d", &T);

	while (T--) {
		scanf("%s", answers);

		int ans = 0;
		for (i = 0; i <= 15; i++)
		{
			if (is_same(cards[i], answers))
				ans = i + 1;
		}
		printf("%d\n", ans);

		for (i = 0; i < 5; i++)
			answers[i] = 0;
	}

	return 0;
}
