/*
Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode *walk = NULL;
	struct ListNode *pre = NULL;

	for(walk = head; walk != NULL; walk = walk->next)
	{
		if(walk->val == val)
		{
			if(walk == head)
			{
				head = head->next;
			}
			else
			{
				pre->next = walk->next;
			}
		}
		else
			pre = walk;
	}

	return head;
}

