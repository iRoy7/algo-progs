/* 
input:
3
4
400 100 100 100
Danny Messer
Stella Bonasera
Stella Bonasera
Mac Taylor
3
200 200 200
Gil
Sarah
Warrick
3
100 200 50
Haratio Caine
horatio caine
YEAAAAAAH
========================
outputs:
3 1 2 0
0 1 2
2 0 1
*/

#include <stdio.h>
#include <map>
#include <string>
using namespace std;

#define SZ_N 51
#define SZ_STR 128

int N;
char users[SZ_N][SZ_STR];
int duration[SZ_N];
bool done[SZ_N];
int ans[SZ_N];

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < SZ_N; i++)
	{
		duration[i] = ans[i] = 0;
		done[i] = false;
		for (j = 0; j < SZ_STR; j++)
			users[i][j] = 0;
	}
}

static void
make_schedule()
{
	map<string, long long> jobTime;

	int i;
	for (i = 0; i < N; i++)
		jobTime[users[i]] += duration[i];

	int ans_cnt = 0;
	while (ans_cnt < N)
	{
		string next;
		for (i = 0; i < N; i++)
		{
			if (!done[i] && (next.empty()
				|| jobTime[users[i]] < jobTime[next]))
				next = users[i];
		}

		for (i = 0; i < N; i++)
		{
			if (users[i] == next)
			{
				done[i] = true;
				ans[ans_cnt++] = i;
			}
		}
	}
}

int main()
{
	freopen("batch_list.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &duration[i]);
		for (i = 0; i < N; i++)
			scanf(" %[^\n]\n", &users[i]);

		make_schedule();

		for (i = 0; i < N; i++)
			printf("%d ", ans[i]);
		printf("\n");

		clear_buf();
	}

	return 0;
}
