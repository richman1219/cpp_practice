#include <iostream>  // Basic input and output library
#include <cstdlib>   // system("pause")
#include "binary_tree_v1.h"


using namespace std;

extern void main_same_tree();


// Time:  O(n)
// Space: O(h), h is height of binary tree

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class solution_same_tree
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q) 
	{
		if (!p && !q) 
		{
			return true;
		}
		return p && q && p->val == q->val &&
			isSameTree(p->left, q->left) &&
			isSameTree(p->right, q->right);
	}
};

