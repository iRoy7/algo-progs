/*
This source code is from
https://www.scribd.com/doc/13597352/C-program-for-list-implementation-using-array
*/

#include <stdio.h>
#include <conio.h>
const int MAX = 20;

struct
{
	int list[MAX];
	int element;
	int pos;
	int length;
}l;

int menu();
void create();
void insert(int, int);
void del(int);
void find(int);
void display();
bool islistfull();
bool islistempty();

int main()
{
	int ch;
	int element;
	int pos;

	l.length = 0;

	while (1)
	{
		ch = menu();

		switch (ch)
		{
		case 1:
			l.length = 0;
			create();
			break;
		case 2:
			if (islistfull() != true)
			{
				printf("\tEnter the New element: ");
				scanf("%d", &element);
				printf("\tEnter the Position: ");
				scanf("%d", &pos);
				insert(element, pos);
			}
			else
			{
				printf("\tList is Full. Cannot insert");
				printf("\nPress any key to continue..");
				getch();
			}
			break;
		case 3:
			if (islistempty() != true)
			{
				printf("Enter the position of element to be deleted: ");
				scanf("%d", &pos);
				del(pos);
			}
			else
			{
				printf("List is Empty.");
				printf("\nPress any key to continue..");
				getch();
			}
			break;
		case 4:
			printf("No. of elements in the list is %d", l.length);
			printf("\nPress any key to continue..");
			getch();
			break;
		case 5:
			printf("Enter the element to be searched: ");
			scanf("%d", &element);
			find(element);
			break;
		case 6:
			display();
			break;
		case 7:
			return 0;
			break;
		default:
			printf("Invalid Choice");
			printf("\nPress any key to continue..");
			getch();
		}
	}

	return 0;
}

int menu()
{
	int ch;
	printf("\n\t\t*****************************************\n");
	printf("\t\t++++ List Implementation Using Arrays ++++\n");
	printf("\n\t\t*****************************************\n");
	printf("\t1. Create\n\t2. Insert\n\t3. Delete\n\t4. Count\n\t5. Find\n\t6. Display\n\t7. Exit\n\nEnter your choice:> ");
	scanf("%d", &ch);
	printf("\n\n");
	return ch;
}

void create()
{
	int element;
	int flag = 1;
	while (flag == 1)
	{
		printf("Enter an element: ");
		scanf("%d", &element);
		l.list[l.length] = element;
		l.length++;
		printf("To insert another element press '1': ");
		scanf("%d", &flag);
	}
}

void display()
{
	for (int i = 0; i < l.length; i++)
		if (l.list[i])
			printf("Element %d: %d\n", i + 1, l.list[i]);
	
	printf("Press any key to continue..");
	getch();
}

void insert(int element, int pos)
{
	if (pos == 0)
	{
		printf("\n\nCannot insert at zeroth position");
		printf("\nPress any key to continue..");
		getch();
		return;
	}
	if (pos - 1 > l.length)
	{
		printf("\n\nOnly %d elements exit. Cannot insert at %d position", l.length, pos);
		printf("\nPress any key to continue..");
		getch();
	}
	else
	{
		for (int i = l.length; i >= pos - 1; i--)
		{
			l.list[i + 1] = l.list[i];
		}
		l.list[pos - 1] = element;
		l.length++;
	}
}

void del(int pos)
{
	if (pos == 0)
	{
		printf("\n\nCannot insert at zeroth position");
		printf("\nPress any key to continue..");
		getch();
		return;
	}
	if (pos > l.length)
	{
		printf("\n\nOnly %d elements exit. Cannot insert at %d position", l.length, pos);
		printf("\nPress any key to continue..");
		getch();
	}

	for (int i = pos - 1; i < l.length; i++)
	{
		l.list[i] = l.list[i + 1];
	}
	l.length--;
}

void find(int element)
{
	int flag = 1;

	for (int i = 0; i < l.length; i++)
	{
		if (l.list[i] == element)
		{
			printf("%d exists at %d position", element, i + 1);
			flag = 0;
			printf("\nPress any key to continue..");
			getch();
			break;
		}
	}

	if (flag == 1)
	{
		printf("Element not found.\nPress any key to continue..");
		getch();
	}
}

bool islistfull()
{
	if (l.length == MAX)
		return true;
	else
		return false;
}

bool islistempty()
{
	if (l.length == 0)
		return true;
	else
		return false;
}


