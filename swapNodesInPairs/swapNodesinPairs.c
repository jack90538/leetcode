/*
Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode *walk = NULL;
	struct ListNode *nextNode = NULL;
	struct ListNode *pre = NULL;
	
	for(walk = head; walk != NULL; walk = walk->next)
	{
		nextNode = walk->next;
		
		if(walk->next == NULL)
			break;
		if(pre == NULL)
		{
			walk->next = nextNode->next;
			nextNode->next = walk;
			head = nextNode;
		}
		else
		{
			walk->next = nextNode->next;
			nextNode->next = walk;
			pre->next = nextNode;
		}
		pre = walk;
		
	}

	return head;
}

