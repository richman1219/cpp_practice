#pragma once

// Time:  O(n)
// Space: O(h)

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution_two_sum_bst {
public:
	bool findTarget(TreeNode* root, int k) {
		if (!root) {
			return false;
		}
		BSTIterator left(root, true), right(root, false);
		while (*left < *right) {
			if (*left + *right == k) {
				return true;
			}
			else if (*left + *right < k) {
				++left;
			}
			else {
				++right;
			}
		}
		return false;
	}

private:
	class BSTIterator {
	public:
		BSTIterator(TreeNode *root, bool forward) :
			node_(root),
			forward_(forward) {
			++(*this);
		};

		int operator*() {
			return cur_;
		}

		void operator++() {
			while (node_ || !s_.empty()) {
				if (node_) {
					s_.emplace(node_);
					node_ = forward_ ? node_->left : node_->right;
				}
				else {
					node_ = s_.top();
					s_.pop();
					cur_ = node_->val;
					node_ = forward_ ? node_->right : node_->left;
					break;
				}
			}
		}

	private:
		TreeNode* node_;
		bool forward_;
		stack<TreeNode*> s_;
		int cur_;
	};
};


void main_two_sum_bst()
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
	//vector<string> result;
	bool result;
	Solution_two_sum_bst solution;
	result = solution.findTarget(root, 9);

	cout << endl << result << endl;
	/*
	for (int i = 0; i<result.size(); i++)
	{
		cout << result[i] << endl;
	}
	*/
	cout << "\n\ntest done" << endl;
	system("pause");

}