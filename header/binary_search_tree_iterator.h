#pragma once

// Time:  O(1), amortized
// Space: O(h)

/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
* Example of iterate a tree:
* Solution iterator = Solution(root);
* while (iterator.hasNext()) {
*    TreeNode * node = iterator.next();
*    do something for node
*/
class Solution_BSTiterator {
public:
	//@param root: The root of binary tree.
	Solution_BSTiterator(TreeNode *root) {
		curr = root;
	}

	//@return: True if there has next node, or false
	bool hasNext() {
		return !s.empty() || curr != nullptr;
	}

	//@return: return next node
	TreeNode* next() {
		// Go to left most descendant.
		while (curr != nullptr) {
			s.emplace(curr);
			curr = curr->left;
		}
		curr = s.top(); // Left most node.
		
		TreeNode *node = curr;
		curr = curr->right; // Visit right child.

		return node;
	}
private:
	stack<TreeNode *> s;
	TreeNode *curr;
};


void main_binary_search_tree_iterator()
{
	cout << "test start\n" << endl;
	//...............tree 1..............
	cout << "tree2...........\n" << endl;
	BST bst;
	int values[] = { 5, 4, 2, 7, 6 };
	int arr_len = (sizeof(values) / sizeof(*values));

	//start from here 
	bst.add_elements(values, arr_len);

	TreeNode *root;
	root = bst.get_root();
	bst.display(root, 1);

	//................solution...........
	vector<int> result;
	Solution_BSTiterator solution(root);

	cout << endl;
	while (solution.hasNext()) {
		TreeNode * node = solution.next();
		cout << node->val << endl;
	}

	cout << "\n\ntest done" << endl;
	system("pause");

}