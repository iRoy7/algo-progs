/*
INPUT:
1
4
0 1 0 0
1 1 1 0
1 0 1 1
1 0 1 0
==========
OUTPUT:
2
*/
#include <stdio.h>
#define NMAX 101
#define INT_MAX 2147483647

int GR[NMAX][NMAX];
int dist[NMAX][NMAX];
bool visited[NMAX][NMAX];
int N;

static void
min_Dist(int *y, int *x)
{
	int i, j;
	int min_y, min_x;
	int min = INT_MAX;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (visited[i][j] == false && dist[i][j] <= min)
			{
				min = dist[i][j];
				*y = i;
				*x = j;
			}
		}
	}
}

static bool
Safe(int y, int x)
{
	return (y < 0 || x < 0 || y > N - 1 || x > N - 1) ? false : true;
}

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

static void
DA()
{
	int i, count = 0;

	dist[0][0] = 0;
	visited[0][0] = true;
	dist[0][1] = GR[0][1];
	dist[1][0] = GR[1][0];

	for (count = (N * N - 1); count > 0; count--)
	{
		int cury = 0, curx = 0;
		
		min_Dist(&cury, &curx);
		visited[cury][curx] = true;

		for (i = 0; i < 4; i++)
		{
			int ny, nx;
			ny = cury + dy[i];
			nx = curx + dx[i];

			if (Safe(ny, nx) // safe zone
				&& !visited[ny][nx] // not visited yet
				&& dist[cury][curx] != INT_MAX // selected
				&& (dist[ny][nx] > dist[cury][curx] + GR[ny][nx]))
			{
				// Update Min Distance(Weight)
				dist[ny][nx] = dist[cury][curx] + GR[ny][nx];
			}
		}
	}
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i, j;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				char x;
				scanf(" %c", &x);
				GR[i][j] = x - '0';
				dist[i][j] = INT_MAX;
				visited[i][j] = false;
			}
		}

		/* Djikstra */
		DA();

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				printf("%d ", dist[i][j]);
			}
			printf("\n");
		}

		printf("#%d %d\n", tc, dist[N - 1][N - 1]);

		//clear();
	}

	return 0;
}
