#include <stdio.h>
#define MAXIS 10

struct Stack {
	int size;
	int data[MAXIS];
	Stack(viod) : size(0) {}
	void init() { size = 0; }
	bool isEmpty() { return size == 0; }
	void push(int x) { data[size++] = x; }
	int pop() { return (isEmpty())? -1 : data[--size]; }
	int top() { return (isEmpty())? -1 : data[size - 1]; }

};

struct Stack st;

int main() 
{
    st.init();
	printf("current stack size -> %d\n", st.size);
	printf("is a stack empty?  -> %d\n", st.isEmpty());
	st.push(1);
	printf("Push a number, size-> %d\n", st.size);
	st.push(2);
	printf("Push second  , size-> %d\n", st.size);
	printf("Pop a number , num -> %d\n", st.pop());
	printf("current stack size -> %d\n", st.size);
	st.push(3);
	printf("Push third   , size-> %d\n", st.size);
	printf("Top a number , num -> %d\n", st.top());
	printf("current stack size -> %d\n", st.size);
	printf("is a stack empty?  -> %d\n", st.isEmpty());
	st.pop();
	st.pop();
	
	if (st.pop() == -1)
		printf("Underflow~!\n");
	
	for (int i = 0; i <= 11; i++) {
		st.push(i);
		if (st.size > MAXIS)
			printf("Overflow~!\n");
	}
	
	return 0;
}
