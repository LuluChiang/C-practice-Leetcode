#include "Tree.h"



/*
100. Same Tree
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
Input:      1          1
			/           \
			2             2
			[1,2],     [1,null,2]
Output: false
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
		return true;
	else
		return false;
}

/*
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
*/
bool isMirror(struct TreeNode* l, struct TreeNode* r)
{
	if (l == NULL || r == NULL)
		return l == r;
	if (l->val != r->val)
		return false;
	return isMirror(l->left, r->right) && isMirror(l->right, r->left);
}
bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	return isMirror(root->left, root->right);
}

/*
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.
*/
int maxDepth(struct TreeNode* root) 
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

/*
94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.
Follow up: Recursive solution is trivial, could you do it iteratively?

* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* inorderTraversal(struct TreeNode* root, int* returnSize) //why cant memcpy with len = 0?
{
	*returnSize = 0;
	if (root == NULL)
		return NULL;
	int nleft = 0, nright = 0, i;
	int* left = inorderTraversal(root->left, &nleft);
	int* right = inorderTraversal(root->right, &nright);


	*returnSize = nleft + nright + 1;
	int* rtnAr = (int*)malloc(sizeof(int) * (*returnSize));
	/*memcpy(rtnAr, left, nleft);
	memcpy(&rtnAr[nleft], &root->val, 1);
	memcpy(&rtnAr[nleft+1], right, nright);*/
	for (i = 0; i < nleft; i++)
		rtnAr[i] = left[i];
	rtnAr[nleft] = root->val;
	for (i = 0; i < nright; i++)
		rtnAr[nleft + 1 + i] = right[i];


	free(left);
	free(right);

	return rtnAr;

}

/*
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
bool isBalanced(struct TreeNode* root) 
{
	if (!root)
		return true;	
	return AbsoluteValue(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);	
}
/*
112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.
Example:
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
bool hasPathSum(struct TreeNode* root, int sum) 
{
	if (!root)
		return false;
	if (root->val == sum && root->left == NULL && root->right == NULL)
		return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
/*
226. Invert Binary Tree
Invert a binary tree.
Example:
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:
	 4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can¡¦t invert a binary tree on a whiteboard so f*** off.
*/
struct TreeNode* invertTree(struct TreeNode* root)
{
	if (!root)
		return NULL;
	struct TreeNode *temp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(temp);
	return root;
}