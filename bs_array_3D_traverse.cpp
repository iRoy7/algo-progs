#include <stdio.h>
#define SZ_C 201

int cmd[SZ_C];
int cmd_cnt;
int rt_y, rt_x;
int cur_dir;
int cur_aspt;
int prev_aspt;
int N, K;

static void
clear()
{
	int i;
	for (i = 0; i < SZ_C; i++)
		cmd[i] = 0;
}

static void
move_vir(int *y, int *x)
{
	if (cur_dir == 1)
		*y = rt_y - 1, *x = rt_x;
	else if (cur_dir == 4)
		*y = rt_y + 1, *x = rt_x;
	else if (cur_dir == 2)
		*y = rt_y, *x = rt_x + 1;
	else if (cur_dir == 3)
		*y = rt_y, *x = rt_x - 1;
	else
		printf("ERR: Wrong direction (%d) \n", cur_dir);
	return;
}

static int
up_dir_next_aspect_from_top(int prev, int y, int x)
{
	int next_aspect = 0;
	if (prev == 1) next_aspect = 2;
	else if (prev == 2) next_aspect = 1;
	else if (prev == 3) next_aspect = 4;
	else if (prev == 4) next_aspect = 3;

	rt_y = 0;
	rt_x = (N - 1) - x;

	return next_aspect;
}

static int
right_dir_next_aspect_from_top(int prev, int y, int x)
{
	int next_aspect = 0;
	if (prev == 1) next_aspect = 3;
	else if (prev == 2) next_aspect = 4;
	else if (prev == 3) next_aspect = 2;
	else if (prev == 4) next_aspect = 1;

	rt_y = 0;
	rt_x = (N - 1) - y;

	return next_aspect;
}

static int
left_dir_next_aspect_from_top(int prev, int y, int x)
{
	int next_aspect = 0;
	if (prev == 1) next_aspect = 4;
	else if (prev == 2) next_aspect = 3;
	else if (prev == 3) next_aspect = 1;
	else if (prev == 4) next_aspect = 2;

	rt_y = 0;
	rt_x = y;

	return next_aspect;
}

static int
down_dir_next_aspect_from_top(int prev, int y, int x)
{
	int next_aspect = 0;
	if (prev == 1) next_aspect = 1;
	else if (prev == 2) next_aspect = 2;
	else if (prev == 3) next_aspect = 3;
	else if (prev == 4) next_aspect = 4;

	rt_y = 0;
	rt_x = x;

	return next_aspect;
}

static void
check_n_move(int y, int x)
{
	// 전면: (1) ======================================================
	if (cur_aspt == 1)
	{
		if (y > N - 1)
		{
			printf("|||\n");
			return;
		}
		else if (y < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 5;
			// 좌표 변경
			rt_y = N - 1;
			printf("(UP)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x > N - 1)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 3;
			// 좌표 변경
			rt_x = 0;
			printf("(RIGHT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 4;
			// 좌표 변경
			rt_x = N-1;
			printf("(LEFT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else // 단순이동
		{
			rt_y = y, rt_x = x;
			printf("(*)-> (%d, %d)\n", rt_y, rt_x);
		}
	}
	// 후면: (2) ======================================================
	else if (cur_aspt == 2)
	{
		if (y > N - 1)
		{
			printf("|||\n");
			return;
		}
		else if (y < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 5;
			// 좌표 변경
			rt_y = N - 1;
			printf("(UP)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x > N - 1)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 4;
			// 좌표 변경
			rt_x = 0;
			printf("(RIGHT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 3;
			// 좌표 변경
			rt_x = N - 1;
			printf("(LEFT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else // 단순이동
		{
			rt_y = y, rt_x = x;
			printf("(*)-> (%d, %d)\n", rt_y, rt_x);
		}
	}
	// 오른쪽면: (3) ======================================================
	else if (cur_aspt == 3)
	{
		if (y > N - 1) 
		{
			printf("|||\n");
			return;
		}
		else if (y < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 5;
			// 좌표 변경
			rt_y = N - 1;
			printf("(UP)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x > N - 1)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 2;
			// 좌표 변경
			rt_x = 0;
			printf("(RIGHT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 1;
			// 좌표 변경
			rt_x = N - 1;
			printf("(LEFT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else // 단순이동
		{
			rt_y = y, rt_x = x;
			printf("(*)-> (%d, %d)\n", rt_y, rt_x);
		}
	}
	// 왼쪽면: (4) ======================================================
	else if (cur_aspt == 4)
	{
		if (y > N - 1) 
		{
			printf("|||\n");
			return;
		}
		else if (y < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 5;
			// 좌표 변경
			rt_y = N - 1;
			printf("(UP)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x > N - 1)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 1;
			// 좌표 변경
			rt_x = 0;
			printf("(RIGHT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x < 0)
		{
			prev_aspt = cur_aspt;
			cur_aspt = 2;
			// 좌표 변경
			rt_x = N - 1;
			printf("(LEFT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else // 단순이동
		{
			rt_y = y, rt_x = x;
			printf("(*)-> (%d, %d)\n", rt_y, rt_x);
		}
	}
	// 윗면: (5) ======================================================
	else if (cur_aspt == 5)
	{
		if (y < 0) // 위
		{
			cur_aspt = up_dir_next_aspect_from_top(prev_aspt, y, x);
			prev_aspt = 5;
			cur_dir = 4;
			printf("(UP)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (y > N - 1) // 아래
		{
			cur_aspt = down_dir_next_aspect_from_top(prev_aspt, y, x);
			prev_aspt = 5;
			cur_dir = 4;
			printf("(DOWN)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x > N - 1) // 오른쪽
		{
			cur_aspt = right_dir_next_aspect_from_top(prev_aspt, y, x);
			prev_aspt = 5;
			cur_dir = 4;
			printf("(RIGHT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else if (x < 0) // 왼쪽
		{
			cur_aspt = left_dir_next_aspect_from_top(prev_aspt, y, x);
			prev_aspt = 5;
			cur_dir = 4;
			printf("(LEFT)-> (%d, %d)\n", rt_y, rt_x);
		}
		else // 단순이동
		{
			rt_y = y, rt_x = x;
			printf("(*)-> (%d, %d)\n", rt_y, rt_x);
		}
	}
	else
	{
		printf("ERR: Wrong aspects (%d)\n", cur_aspt);
	}
}

static void
robot_move_foward(int x)
{
	if (x != 1)
	{
		printf("ERR: wrong command (%d)\n", x);
		return;
	}

	int ny = 0, nx = 0;
	move_vir(&ny, &nx);
	check_n_move(ny, nx);
	return;
}

static void
update_direction(int x)
{
	if (cur_dir == 1) // 위
	{
		cur_dir = x;
	}
	else if (cur_dir == 4) // 아래
	{
		cur_dir = 5 - x;
	}
	else if (cur_dir == 2) // 우측
	{
		(cur_dir == x) ? cur_dir = 4 : cur_dir = 1;
	}
	else if (cur_dir == 3) // 좌측
	{
		(cur_dir == x) ? cur_dir = 4 : cur_dir = 1;
	}
}

int main()
{
	freopen("robot_cleaner.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, tc, i;

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		rt_y = 0, rt_x = 0;
		cmd_cnt = 0;
	    cur_dir = 1;
		cur_aspt = 1, prev_aspt = 0;

		scanf("%d %d %d", &N, &rt_y, &rt_x);
		rt_y--, rt_x--;

		scanf("%d", &cmd_cnt);
		for (i = 1; i <= cmd_cnt; i++)
		{
			scanf("%d", &cmd[i]);
		}

		for (i = 1; i <= cmd_cnt; i++)
		{
			int x = cmd[i];

			if (x > 1)
			{
				update_direction(x);
			}
			else
			{
				robot_move_foward(x);
			}
		}

		printf("#%d %d\n", tc, cur_aspt);

		clear();
	}

	return 0;
}
