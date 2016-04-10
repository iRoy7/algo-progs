#include <stdio.h>
#define QSIZE 100
struct Queue {
	Queue(): head(0), tail(0) {}
	void init() { head = 0, tail = 0; }
	bool isEmpty() { return head == tail; }
	void push(int x) { containers[tail++] = x; }
	int pop() { return (isEmpty())? -1: containers[head++]; }
	int front() { return (isEmpty())? -1: containers[head]; }
	int size() { return tail - head; }
	int head, tail;
	int containers[QSIZE];
};
struct Queue q;
int main()
{
	q.init();
	printf("current queue size  -> %d\n", q.size());
	printf("is a Queue empty?   -> %d\n", q.isEmpty());
	q.push(9);
	printf("push the first size -> %d\n", q.size());
	q.push(8);
	printf("push the second size-> %d\n", q.size());
	printf("pop the first item  -> %d\n", q.pop());
	q.push(7);
	printf("push the third size -> %d\n", q.size());
	printf("get the front item  -> %d\n", q.front());
	printf("current queue size  -> %d\n", q.size());
	for (int i = 1; i <= 4; i++)
		if (q.pop() == -1)
			printf("Under flow~!\n");
	printf("current queue size  -> %d\n", q.size());
	return 0;
}
