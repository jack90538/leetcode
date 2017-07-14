/*
Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root)
{
	static int min = 1;
	static int current = 0;
	int currentBak = 0; 

	if(root == NULL)
	{
		if(current < min)
			min = current;
	}
	else
	{
		current++;
		currentBak = current;
		minDepth(root->left);
		current = currentBak;
		minDepth(root->right);
		current = currentBak;
	}
	
	return min;
}


