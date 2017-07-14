#include <stdio.h>
#include <stdlib.h>

typedef struct list_s{
	int val;
	struct list_s *next;
}list_t;

int findPre(list_t *head, list_t *tail, list_t **ret)
{
	list_t *walk = NULL;

	for(walk = head; walk != NULL && walk->next != tail; walk = walk->next)
		;

	*ret = walk;

	return 0;
}

int reverseList(list_t *head, list_t *tail, list_t **newHead)
{
	list_t *pre = NULL;
	list_t *prepre = NULL;

	do
	{
		findPre(head, tail, &pre);
		findPre(head, pre, &prepre);

		if(pre != NULL)
		{
			if(*newHead == NULL)
				*newHead = tail;
			pre->next = NULL;
			tail->next = pre;
			tail = pre;
		}
	} while(pre != NULL && prepre != NULL);
	
	return 0;
}


int printList(list_t *head)
{
	list_t *walk = NULL;
	
	for(walk = head; walk != NULL; walk = walk->next)
		printf("val %d\n", walk->val);
	return 0;
}


int main()
{
	list_t *head = NULL;
	list_t *tail = NULL;
	list_t *node = NULL;
	
	list_t *newHead = NULL;
	int i;
	
	for(i = 0; i < 10; i++)
	{
		node = malloc(sizeof(list_t));
		node->val = i+1;
		
		if(head == NULL)
		{
			head = tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	
	printList(head);
	reverseList(head, tail, &newHead);
	printList(newHead);
	
	return 0;
}


int test(list_t *head, list_t *tail, list_t **newHead)
{
	list_t *walk;
	list_t *pre;

	while(head)
	{
		pre = head;
		walk = head->next;
		head = walk->next;
		walk->next = pre;
	}
	
	*newHead = walk;
	return 0;
}
