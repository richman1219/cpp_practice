#pragma once

#include <vector>
#include <stack>

#include <string>

using namespace std;

// Time:  O(n * h)
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
*/
class Solution_binary_tree_paths {
public:
	/**
	* @param root the root of the binary tree
	* @return all root-to-leaf paths
	*/
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		vector<TreeNode *> path;
		binaryTreePathsRecu(root, &path, &result);
		return result;
	}

	void binaryTreePathsRecu(TreeNode *node, vector<TreeNode *> *path,
		vector<string> *result) {
		if (!node) {
			return;
		}

		if (!node->left && !node->right) {
			string ans = "";
			for (const auto& n : *path) {
				ans.append(to_string(n->val).append("->"));
			}
			result->emplace_back(move(ans.append(to_string(node->val))));
		}

		if (node->left) {
			path->emplace_back(node);
			binaryTreePathsRecu(node->left, path, result);
			path->pop_back();
		}

		if (node->right) {
			path->emplace_back(node);
			binaryTreePathsRecu(node->right, path, result);
			path->pop_back();
		}
	}
};

void main_binary_tree_paths()
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
	vector<string> result;
	Solution_binary_tree_paths solution;
	result = solution.binaryTreePaths(root);

	cout << endl;
	for (int i = 0; i<result.size(); i++)
	{
		cout << result[i]<<endl;
	}

	cout << "\n\ntest done" << endl;
	system("pause");

}