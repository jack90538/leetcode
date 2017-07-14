/*
Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void insertList(struct ListNode** ret, struct ListNode** tail, struct ListNode* node)
{
	if(*ret == NULL)
	{
		*ret = *tail = node;
	}
	(*tail)->next = node;
	*tail = (*tail)->next;
	node->next = NULL;
}
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* ret = NULL;
	struct ListNode* tail = NULL;
	struct ListNode* temp = NULL;

	while(l1 != NULL || l2 != NULL)
	{
		if(l1 == NULL && l2 != NULL)
		{
			temp = l2;
			l2 = l2->next;
			insertList(&ret, &tail, temp);
		}
		else if(l1 != NULL && l2 == NULL)
		{
			temp = l1;
			l1 = l1->next;
			insertList(&ret, &tail, temp);
		}
		else if(l1->val < l2->val)
		{
			temp = l1;
			l1 = l1->next;
			insertList(&ret, &tail, temp);
		}
		else
		{
			temp = l2;
			l2 = l2->next;
			insertList(&ret, &tail, temp);
		}
	}

	return ret;
}
