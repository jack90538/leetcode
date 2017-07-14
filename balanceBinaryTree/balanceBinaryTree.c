/* Balanced Binary Tree */
/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int treeHeight(struct TreeNode* root)
{
	int left;
	int right;
	
	if(root == NULL)
		return 0;
	else
	{
		left = treeHeight(root->left);
		right = treeHeight(root->right);

		if(left > right)
			return 1+left;
		else
			return 1+right;
	}
}

bool isBalanced(struct TreeNode* root)
{
	int leftHeight;
	int rightHeight;
	int result = 1;

	if(root == NULL)
		return result;
	leftHeight = treeHeight(root->left);
	rightHeight = treeHeight(root->right);
	// check left sub tree and right sub tree diff than 1
	if(leftHeight > rightHeight && leftHeight-rightHeight > 1)
		return 0;
	else if(rightHeight > leftHeight && rightHeight - leftHeight > 1)
		return 0;
	// check left sub tree and right sub tree is balanced tree
	if(leftHeight > 1 && rightHeight > 1)
		return result && isBalanced(root->left) && isBalanced(root->right);
	else if(leftHeight > 1)
		return result && isBalanced(root->left);
	else if(rightHeight > 1)
		return result && isBalanced(root->right);
	else
		return result;
}