/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* walk, *tmp;
	
	for(walk = head; walk!=NULL; )
	{
		if(walk->next != NULL && walk->val == walk->next->val)
		{
			tmp = walk->next;
			walk->next = tmp->next;
			free(tmp);
		}
		else
			walk=walk->next;
	}
	return head;
}


