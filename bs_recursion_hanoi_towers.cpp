#include <stdio.h>

static void 
__hanoi_recursion(int num, int from, int to, int spare)
{
	if (num == 1) {
		printf("%d -> %d\n", from, to);
		return;
	}
	else {
		__hanoi_recursion(num - 1, from, spare, to);
		__hanoi_recursion(1, from, to, spare);
		__hanoi_recursion(num - 1, spare, to, from);
	}
	return;
}

int main()
{
	setbuf(stdout, NULL);
	
	int N;
	scanf("%d", &N);
	if (N > 1)
		printf("%d\n", (1 << N) - 1);
	else
		printf("%d\n", N);
		
	__hanoi_recursion(N, 1, 3, 2);
	
	return 0;
}
