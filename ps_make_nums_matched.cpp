#include <stdio.h>
#define MAX_NP 10001
#define QR 101

struct Queue {
	int head, tail;
	int containers[QR];
	Queue(void) :head(0), tail(0) {}
	void init() { head = tail = 0; }
	bool is_Empty() { return head == tail; }
	void enqueue(int x) { containers[tail++] = x; }
	int dequeue() { return containers[head++]; }
	int front() { return containers[head]; }
};

int l, r; // l->left, r->right
int NP[MAX_NP];
struct Queue q;
int visited[MAX_NP];
int step_cnt[MAX_NP];

static void
clear_buf()
{
	int i;
	for (i = 0; i <= MAX_NP; i++)
		visited[i] = step_cnt[i] = 0;
}

static int
create_num(int tmp, int index, int digit)
{
	int num;
	char s[5];

	if (index == 0 && digit == 0) // is not prime
		return -1;
		
	sprintf(s, "%d", tmp);
	s[index] = digit + '0';
	sscanf(s, "%d", &num);

	return num;
}

static void
make_matched(int left)
{
	q.init();
	step_cnt[left] = 0;
	visited[left] = 1;

	q.enqueue(left);
	
	while (!q.is_Empty())
	{
		int i, j, x;
		x = q.front();
		/* check x and do something */
		if (x == r)
			break;
			
		q.dequeue();

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j <= 9; j++)
			{
				int nx = create_num(x, i, j);
				if (nx != -1)
				{
					if (!NP[nx] && !visited[nx])
					{
						visited[nx] = 1;
						step_cnt[nx] = step_cnt[x] + 1;
						q.enqueue(nx);
					}
				}
			}
		}
	}
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, i, j;

	// generate primes
	NP[0] = NP[1] = 1;
	for (i = 2; (i*i) < MAX_NP; i++)
		if (!NP[i])
			for (j = (i*i); j < MAX_NP; j += i)
				NP[j] = 1;
				
	// test case numbers
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		// inputs
		scanf("%d%d", &l, &r);

		// base cases
		if (l == r)
		{ 
			printf("Match!\n");
			continue;
		}
		
		if (!NP[l] == 0 || !NP[r] == 0)
		{
			printf("No way!\n");
			continue;
		}

		// solve
		make_matched(l);

		// output
		printf("%d\n", step_cnt[r]);

		// clear buffer
		clear_buf();
	}

	return 0;	
}
