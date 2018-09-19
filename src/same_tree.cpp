# include <iostream>
# include <cstdlib>
# include "binary_tree_v1.h"
# include "same_tree.h"

using namespace std;

void main_same_tree()
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

	//.................tree 2............
	cout << "\ntree2............\n" << endl;
	BST bst2;
	int values2[] = { 5, 3, 2, 7, 6 };
	arr_len = (sizeof(values2) / sizeof(*values2));

	//start from here 
	bst2.add_elements(values2, arr_len);

	TreeNode *root2;
	root2 = bst2.get_root();
	bst2.display(root2, 1);

	//................solution...........
	bool result;
	solution_same_tree solution;
	result = solution.isSameTree(root, root2);
	cout << '\n'<< result << endl;

	cout << "\ntest done" << endl;
	system("pause");

}
