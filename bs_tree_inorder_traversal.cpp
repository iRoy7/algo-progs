#include <stdio.h>
#define SZ_N 12
///////////////////////////////
/* Tree Map */
/*
[p][0]: Left idx
[p][1]: Right idx
[p][2]: Parent idx
[p][3]: parent val
[p][4]: parent left val
[p][5]: parent right val

INPUT:
1
5
1 - 2 3
2 - 4 5
3 1 0
4 8 8
5 6 5
*/
int treeM[SZ_N][7];
char str[16];
int N;

static void
tree_inorder_traversal(int tn)
{
	if (tn)
	{
		// LvR
		tree_inorder_traversal(treeM[tn][0]);
		printf(" %d -> |", tn);
		tree_inorder_traversal(treeM[tn][1]);
	}
}

int main()
{
	freopen("tree_traversal_input_values.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d ", &N);

		for (i = 0; i < N; i++)
		{
			gets_s(str);
			int p = 0, c1 = 0, c2 = 0;
			char ch[3] = { 0 };
			sscanf(str, "%d %s %d %d", &p, &ch, &c1, &c2);

			size_t len;
			for (len = 0; ch[len]; len++);
			ch[len] = '\0';

			if (ch[0] == '*' || ch[0] == '/' || ch[0] == '+' || ch[0] == '-')
			{
				printf("D1: %d %s %d %d\n", p, ch, c1, c2);

				treeM[p][0] = c1;
				treeM[p][1] = c2;
				treeM[c1][2] = p;
				treeM[c2][2] = p;
				treeM[c1][3] = ch[0] - '0';
				treeM[c2][3] = ch[0] - '0';
				treeM[treeM[p][2]][4] = c1;
				treeM[treeM[p][2]][5] = c2;
			}
			else
			{
				int num = 0;
				sscanf(ch, "%d", &num);

				printf("D2: %d %d %d %d\n", p, num, c1, c2);

				treeM[p][0] = p*2;
				treeM[p][1] = p*2+1;
				treeM[treeM[p][2]][4] = num;
				treeM[treeM[p][2]][5] = c1;
			}
		}

		tree_inorder_traversal(1);
		printf("||\n");
	}

	return 0;
}

