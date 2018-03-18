#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int key;
	struct _node *next; // Pointer to next node
} NODE;

NODE *head, *tail;

void list_init(void)
{
	head = (NODE *)malloc(sizeof(NODE));
	tail = (NODE *)malloc(sizeof(NODE));
	head->next = tail;
	tail->next = tail;
}

NODE *insert_after(int k, NODE *t)
{
	NODE *s;
	s = (NODE *)malloc(sizeof(NODE));
	s->key = k;
	s->next = t->next;
	t->next = s;
	return s;
}

int delete_next(NODE *t)
{
	NODE *s;
	if (t->next == tail)
		return 0;
	s = t->next;
	t->next = t->next->next;
	free(s);
	return 1;
}

NODE *find_node(int k)
{
	NODE *s;
	s = head->next;
	while (s->key != k && s != tail)
		s = s->next;
	return s;
}

NODE *insert_node(int t, int k)
{
	NODE *s;
	NODE *p;
	NODE *r;

	p = head;
	s = p->next;

	while (s->key != k && s != tail)
	{
		p = p->next;
		s = p->next;
	}

	if (s != tail)
	{
		r = (NODE *)malloc(sizeof(NODE));
		r->key = t;
		p->next = r;
		r->next = s;
	}

	return p->next;

}

int delete_node(int k)
{
	NODE *s;
	NODE *p;
	p = head;
	s = p->next;

	while (s->key != k && s != tail)
	{
		p = p->next;
		s = p->next;
	}

	if (s != tail)
	{
		p->next = s->next;
		free(s);
		return 1;
	}
	else
		return 0;
}

NODE *ordered_insert(int k)
{
	NODE *s;
	NODE *p;
	NODE *r;

	p = head;
	s = p->next;

	while (s->key <= k && s != tail)
	{
		p = p->next;
		s = p->next;
	}

	r = (NODE *)malloc(sizeof(NODE));
	r->key = k;
	p->next = r;
	r->next = s;
	return r;
}

NODE *delete_all(void)
{
	NODE *s;
	NODE *t;
	t = head->next;

	while (t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}

	head->next = tail;
	return head;
}

void print_list(NODE *t)
{
	printf("\n");
	while (t != tail)
	{
		printf("%-8d", t->key);
		t = t->next;
	}
}

void main(void)
{
	printf("Simple Linked List\n");

	NODE *t;
	list_init();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	printf("\nInitial Linked List is ");
	print_list(head->next);

	printf("\nFinding 4 is %ssuccessful", find_node(4) == tail ? "un" : "");

	t = find_node(5);
	printf("\nFind 5 is %ssuccessful", t == tail ? "un" : "");

	printf("\nInserting 9 after 5");
	insert_after(9, t);
	print_list(head->next);

	t = find_node(10);
	printf("\nDeleting next last node");
	delete_next(t);
	print_list(head->next);

	t = find_node(3);
	printf("\nDeleting next 3");
	delete_next(t);
	print_list(head->next);

	printf("\nInsert node 2 before 3");
	insert_node(2, 3);
	print_list(head->next);

	printf("\nDeleting node 2");
	if (!delete_node(2))
		printf("\nDeleting 2 is unsuccessful");
	print_list(head->next);

	printf("\nDeleting node 1");
	delete_node(1);
	print_list(head->next);

	printf("\nDeleting all node");
	delete_all();
	print_list(head->next);

}


