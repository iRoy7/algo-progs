#include <stdio.h>
#define SSZ 101
#define SMAX 100
/////////////////////////////////////////////////
int top = -1;
int stack[SSZ];
void init()
{
	top = -1;
	for (int i = 0; i < SSZ; i++)
		stack[i] = 0;
}
void push(int x)
{
	if (top + 1 > SMAX)
	{
		printf("stack overflow\n");
		return;
	}
	else stack[++top] = x;
}
int pop()
{
	if (top == (-1))
	{
		printf("stack underflow\n");
		return (-1);
	}
	else
		return stack[top--];
}
/////////////////////////////////////////////////
void sorted_Insert(int x)
{
	if (top == (-1) || x > stack[top])
	{
		printf("D1: push(%d)\n", x);
		stack[++top] = x;
		return;
	}

	printf("Call sorted_insert!!!\n");
	int tmp = stack[top--];
	sorted_Insert(x);

	printf("D2: push(%d)\n", tmp);
	stack[++top] = tmp;
}

void sort_Stack()
{
	if (top != (-1))
	{
		int x = pop();
		sort_Stack();
		sorted_Insert(x);
	}
}

int main()
{
	init();
	push(30);
	push(-5);
	push(18);
	push(14);
	push(-3);

	sort_Stack();
	//int i;
	//for (i = 0; i < top2 + 1; i++)
	while (top != (-1))
	{
		printf("%d ", stack[top--]);
	}
	printf("\n");

	return 0;
}
