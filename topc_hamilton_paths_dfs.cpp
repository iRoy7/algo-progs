// Hamilton Path with dfs
// get the number of possible paths
// paths = (Group(vital path)+Free)! * 2 Group
// input
/*
4
4
NYYY
YNNN
YNNN
YNNN
3
NYN
YNN
NNN
3
NYY
YNY
YYN
6
NNNNNY
NNNNYN
NNNNYN
NNNNNN
NYYNNN
YNNNNN
-----------------
output
0 4 0 24
*/
#include <stdio.h>
#define SZ_N 51

char road[SZ_N][SZ_N];
bool visited[SZ_N];
int N, cnt;

static void
clear_buf()
{
	int i, j;
	for (i = 0; i < SZ_N; i++)
	{
		visited[i] = false;
		for (j = 0; j < SZ_N; j++)
			road[i][j] = 0;
	}
}

static void
dfs(int city)
{
	int i; 

	visited[city] = true;
	for (i = 0; i < N; i++)
	{
		if (road[city][i] == 'Y' && !visited[i])
			dfs(i);
	}
}

static int
count_Paths()
{
	int group = 0, free = 0;
	int connect[SZ_N] = { 0 };

	long long sum = 1;
	int i, j;

	for (i = 0; i < N; i++)
	{
		int y = 0;
		for (j = 0; j < N; j++)
		{
			if (road[i][j] == 'Y')
			{
				// YYY means times visit the city over one time
				if (2 < ++y) 
					return 0;
			}
		}
		connect[i] = y;
	}

	for (i = 0; i < N; i++)
	{
		// connect[i] == 0 means "not connected"
		if (connect[i] == 0)
		{
			// **** free cities
			// mark as visited.
			visited[i] = true;
			free++;
		}
		else if (connect[i] == 1 && !visited[i])
		{
			// *** vital cities
			// visited all cities
			group++;
			dfs(i);
		}
	}

	// check all cities(Group+Free) are visited
	for (i = 0; i < N; i++)
		if (!visited[i]) 
			return 0;

	// it is possible John to visit all cities
	for (i = 0; i < group + free; i++)
		sum = sum*(i + 1) % 1000000007;

	for (i = 0; i < group; i++)
		sum = sum * 2 % 1000000007;

	return (int)sum;
}

int main()
{
	freopen("hamilton_path_map.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;
	scanf("%d", &T);
	
	for (tc = 1; tc <= T; tc++)
	{
		// intput
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%s", &road[i]);

		// solve
		cnt = -1;
		cnt = count_Paths();

		// output
		printf("%d\n", cnt);

		// clear buf
		clear_buf();
	}
	
	return 0;
}
