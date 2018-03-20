#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int key;
	struct _node *next;
} node;

node *head;

void insert_nodes(int k)
{
	node *t;
	t = (node *)malloc(sizeof(node));
	t->key = 1;
	head = t;

	for (int i = 2; i <= k; i++)
	{
		t->next = (node *)malloc(sizeof(node));
		t = t->next;
		t->key = i;
	}

	t->next = head;
}

void delete_after(node *t)
{
	node *s;
	s = t->next;
	t->next = t->next->next;
	free(s);
}

void josephus(int n, int m)
{
	insert_nodes(n);

	printf("\nAnswer : ");

	node *s, *t;
	s = head;
	for (int i = 0; i < n-1; i++)
		s = s->next;
	t = s;
	printf("%d ", t->next->key);
	delete_after(t);

	while (t != t->next)
	{
		for (int i = 0; i < m - 1; i++)
			t = t->next;
		printf("%d ", t->next->key);
		delete_after(t);
	}
	printf("%d", t->key);
}

void circular_linked_list(void)
{
	int n, m;
	printf("\nIf you want to quit, enter 0 or minus value");

	while (1)
	{
		printf("\nEnter N and M -> ");
		scanf("%d %d", &n, &m);
		if (n <= 0 || m <= 0)
			return;
		josephus(n, m);
	}
}
