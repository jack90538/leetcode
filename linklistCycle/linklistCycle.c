/* Linked List Cycle */
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
	struct ListNode *listArray[65535] = {NULL};
	int i;
	int count = 0;
	struct ListNode *walk = head;
	
	while(walk != NULL)
    {
    	for(i = 0; i < count; i++)
    	{
    		if(walk == listArray[i])
				return 1;
    	}
		listArray[count] = walk;
		count++;

		walk = walk->next;
    }

	return 0;
}


#if 1
/* good solution */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast=head, *slow=head;
    while( slow && fast && fast->next ){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}
#endif
