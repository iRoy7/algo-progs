#include <stdio.h>
#define S_MAXIS 1024
#define Q_MAXIS 2048
struct BasicStack {
	int size;
	int data[S_MAXIS];
	BasicStack():size(0) {}
	void init() { size = 0; }
	bool isEmpty() { return size == 0; }
	void push(int x) { data[size++] = x; }
	int pop() { return (isEmpty())? -1 : data[--size]; }
	int top() { return (isEmpty())? -1 : data[size - 1]; }
};
struct BasicQueue {
	int head, tail;
	int containers[Q_MAXIS];
	BasicQueue() : head(0), tail(0) {}
	void init() { head = 0, tail = 0; }
	bool isEmpty() { return head == tail; }
	void push(int x) { containers[tail++] = x; }
	int pop() { return containers[head++]; }
	int front() { return containers[head]; }
	int size() { return tail - head; }
};
struct BasicQueue bq;
struct myQueue {
	struct BasicStack stNewest, stOldest;
	myQueue() { stNewest.init(), stOldest.init(); }
	int size() { return stNewest.size + stOldest.size; }
	void add(int x) { stNewest.push(x); }
	void shiftStacks() {
		if (stOldest.isEmpty()) 
			while (!stNewest.isEmpty())
				stOldest.push(stNewest.pop());
	}
	int front() { shiftStacks(); return stOldest.top(); }
	int remove() { shiftStacks(); return stOldest.pop(); }
};
struct myQueue myq;
int T;
int main()
{
	freopen("random_int_inputs.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	while (T--) {
		int choice;
		scanf("%d", &choice);
		if (choice <= 5) { // enqueue
			int element;
			scanf("%d", &element);
			bq.push(element);
			myq.add(element);
			printf("Enqueue %d\n", element);
		}
		else if (bq.size() > 0) {
			int top1 = bq.pop();
			int top2 = myq.remove();

			if (top1 != top2)
				printf("FAILURE: Different tops: %d, %d\n", top1, top2);
			printf("Dequeue %d\n", top1);
		}
		if (bq.size() == myq.size()) {
			if (bq.size() > 0 && bq.front() != myq.front())
				printf("FAILURE: Different tops: %d, %d\n", bq.front(), myq.front());
		}
		else
			printf("FAILURE: Different sizes\n");
	}
	printf("Final size of myq's stNew = %d and stOld = %d\n", myq.stNewest.size, myq.stOldest.size);
	return 0;
}
