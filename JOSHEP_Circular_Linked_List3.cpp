// Joshep's problem using circular linked list
// N: Number of people
// S: Choose a person on each step until selecting all
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	char key;
	struct _node *next;
} node;

node *head;

void insert_nodes(int nums)
{
	node *n;
	n = (node *)malloc(sizeof(node));
	n->key = 'A';
	head = n;

	for (int i = 2; i <= nums; i++)
	{
		n->next = (node *)malloc(sizeof(node));
		n = n->next;
		//printf("ROY: %c ", 'A' + (i - 1));
		n->key = 'A'+(i-1);
	}

	n->next = head;
	//printf("\n ROY:header's key -> %c\n", head->key);
}

void delete_after(node *t)
{
	node *s;
	s = t->next;
	t->next = t->next->next;
	free(s);
}

void josephus(int nums, int step)
{
	insert_nodes(nums);

	printf("\nAnswer : ");

	// Move to the last node
	node *s, *t;
	s = head;
	for (int i = 0; i < nums - 1; i++)
		s = s->next;
	t = s;
	// Print the first node
	printf("%c ", t->next->key);

	delete_after(t);
	
	while (t != t->next)
	{
		for (int i = 0; i < step - 1; i++)
			t = t->next;
		printf("%c ", t->next->key);
		delete_after(t);
	}
	// Print the last node
	printf("%c", t->key);
}

int main(void)
{
	int nums, step;
	printf("\nIf you want to quit, enter 0 or minus value");

	while (1)
	{
		printf("\nEnter (N)number of people and (S)step -> ");
		scanf("%d %d", &nums, &step);
		if (nums <= 0 || step <= 0)
			return 0;
		josephus(nums, step);
	}

	return 0;
}
