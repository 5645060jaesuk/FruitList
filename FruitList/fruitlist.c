#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode
{
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void delete_node(ListNode* head, char* index) {
	int k = index;
	ListNode* temp = head;
	ListNode* garbage = NULL;

	while (k-- && temp != NULL)
	{
		temp = temp->link;
	}


	if (temp == NULL || temp->link == NULL)
		return;

	garbage = temp->link;
	temp->link = garbage->link;
	free(garbage);
	printf("\n");
}


ListNode* search_list(ListNode* head, char* value)
{
	ListNode* p = head;

	while (p != NULL)
	{
		if (strcmp(p->data.name, value) == 0) return p;
		p = p->link;
	}
	return NULL;
}

ListNode* search_num(ListNode* head, char* value)
{
	int cnt = 0;
	ListNode* p = head;

	while (p != NULL)
	{
		if (strcmp(p->data.name, value) == 0) return (cnt - 1);
		p = p->link;
		cnt++;
	}
	return NULL;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL\n");
}
int main()
{
	ListNode* head = NULL;
	ListNode* tmp = NULL;
	element data;
	int n;
	char name[100];

	strcpy_s(data.name, sizeof(name), "Peach");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Banana");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Raspberry");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Guava");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Plum");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Cherry");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Grape");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Apple");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Orange");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(name), "Mango");
	head = insert_first(head, data);

	while (1)
	{
		printf("Menu\n");
		printf("(1) Insert new fruit\n");
		printf("(2) Delete the fruit\n");
		printf("(3) Print the deleted list\n");
		printf("(4) Exit\n");
		printf("Enter the Menu : ");
		scanf_s("%d", &n);

		if (n == 1)
		{
			printf("Fruit name to add : ");
			scanf_s("%s", name, sizeof(name));
			strcpy_s(data.name, sizeof(name), name);
			if (search_list(head, name) != NULL)
			{
				printf("%s already exists\n", name);
			}
			else
			{
				head = insert_first(head, data);
				printf("%s has been added\n", name);
			}
			printf("Fruit list : \n");
			print_list(head);
			printf("\n");

		}
		else if (n == 2)
		{
			printf("Fruit name to delete : ");
			scanf_s("%s", name, sizeof(name));
			strcpy_s(data.name, sizeof(name), name);
			printf("\n");
			if (search_list(head, name) != NULL)
			{
				printf("%s has been deleted.\n", name);
				tmp = insert_first(tmp, data);
				delete_node(head, search_num(head, name));

			}
			else
			{
				printf("%s is not on the list.\n", name);
			}
			printf("Fruit list : \n");
			print_list(head);
			printf("\n");
		}

		else if (n == 3)
		{
			if (tmp == NULL)
			{
				printf("List of the deleted fruits : ");
			}
			print_list(tmp);
			printf("\n");
			print_list(head);
		}

		else if (n == 4)
		{
			printf("Exit the program");
			break;
		}
		else
		{
			printf("invalid menu. pleas select again.\n");
		}
	}
}