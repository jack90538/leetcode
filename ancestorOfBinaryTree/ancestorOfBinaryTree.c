/* Lowest Common Ancestor of a Binary Search Tree */
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡§The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡¨

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int inTree(struct TreeNode* root, struct TreeNode* node)
{
	if(root == node)
		return 1;
	if(root == NULL)
		return 0;
	else
		return inTree(root->left, node) | inTree(root->right, node);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    int pInLeft;
	int pInRight;
	int qInLeft;
	int qInRight;

	pInLeft = inTree(root->left, p);
	pInRight = inTree(root->right, p);
	qInLeft = inTree(root->left, q);
	qInRight = inTree(root->right, q);
	
	
	if(p == root)
	{
		return p;
	}
	else if(q == root)
	{
		return q;
	}
	else if((pInLeft && qInRight) || (pInRight && qInLeft))
	{
		return root;
	}
	else if(pInLeft)
	{
		return lowestCommonAncestor(root->left, p, q);
	}
	else	// pInRight
	{
		return lowestCommonAncestor(root->right, p, q);
	}
}

