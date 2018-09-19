#pragma once
#include <vector>
#include <stack>

// Time:  O(n)
// Space: O(h)
class solution_b_tree_inorder {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<pair<TreeNode *, bool>> s;
		s.emplace(root, false);
		while (!s.empty()) {
			bool visited;
			tie(root, visited) = s.top();
			s.pop();
			if (root == nullptr) {
				continue;
			}
			if (visited) {
				res.emplace_back(root->val);
			}
			else {
				s.emplace(root->right, false);
				s.emplace(root, true);
				s.emplace(root->left, false);
			}
		}
		return res;
	}
};

void main_b_tree_inorder()
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
	solution_b_tree_inorder solution;
	result = solution.inorderTraversal(root);

	cout << endl;
	for (int i = 0; i<result.size(); i++)
	{
		cout << result[i];
	}

	cout << "\n\ntest done" << endl;
	system("pause");

}