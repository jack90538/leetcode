/*
Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/

bool checkPathSum(struct TreeNode* root, int sum)
{
	if(root == NULL)
	{
		return false;
	}
	else if(root->left == NULL && root->right == NULL)
	{
		if(root->val == sum)
			return true;
		else
			return false;
	}
	else
	{
		return checkPathSum(root->left, sum-(root->val)) | checkPathSum(root->right, (sum-root->val));
	}
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum)
{
	if(root)
		return checkPathSum(root, sum);
	else
		return false;
}

