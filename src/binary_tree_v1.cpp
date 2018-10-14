/*
* C++ Program To Implement BST
*/
#include <iostream>
#include <cstdlib>
#include "binary_tree_v1.h"

using namespace std;

/*
* Find Element in the Tree
*/
void BST::find(int item, TreeNode **par, TreeNode **loc)
{
	TreeNode *ptr, *ptrsave;
	if (root == NULL)
	{
		*loc = NULL;
		*par = NULL;
		return;
	}
	if (item == root->val)
	{
		*loc = root;
		*par = NULL;
		return;
	}
	if (item < root->val)
		ptr = root->left;
	else
		ptr = root->right;
	ptrsave = root;
	while (ptr != NULL)
	{
		if (item == ptr->val)
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->val)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*loc = NULL;
	*par = ptrsave;
}

/*
* Inserting Element into the Tree
*/
void BST::insert(TreeNode *tree, TreeNode *newTreeNode)
{
	if (root == NULL)
	{
		root = new TreeNode;
		root->val = newTreeNode->val;
		root->left = NULL;
		root->right = NULL;
		cout << "Root TreeNode is Added" << endl;
		return;
	}

	if (tree->val == newTreeNode->val)
	{
		cout << "Element already in the tree" << endl;
		return;
	}
	if (tree->val > newTreeNode->val)
	{
		if (tree->left != NULL)
		{
			insert(tree->left, newTreeNode);
		}
		else
		{
			tree->left = newTreeNode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "TreeNode Added To Left" << endl;
			return;
		}
	}
	else
	{
		if (tree->right != NULL)
		{
			insert(tree->right, newTreeNode);
		}
		else
		{
			tree->right = newTreeNode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout << "TreeNode Added To Right" << endl;
			return;
		}
	}
}

/*
* Delete Element from the tree
*/
void BST::del(int item)
{
	TreeNode *parent, *location;
	if (root == NULL)
	{
		cout << "Tree empty" << endl;
		return;
	}
	find(item, &parent, &location);
	if (location == NULL)
	{
		cout << "Item not present in tree" << endl;
		return;
	}
	if (location->left == NULL && location->right == NULL)
		case_a(parent, location);
	if (location->left != NULL && location->right == NULL)
		case_b(parent, location);
	if (location->left == NULL && location->right != NULL)
		case_b(parent, location);
	if (location->left != NULL && location->right != NULL)
		case_c(parent, location);
	free(location);
}

/*
* Case A
*/
void BST::case_a(TreeNode *par, TreeNode *loc)
{
	if (par == NULL)
	{
		root = NULL;
	}
	else
	{
		if (loc == par->left)
			par->left = NULL;
		else
			par->right = NULL;
	}
}

/*
* Case B
*/
void BST::case_b(TreeNode *par, TreeNode *loc)
{
	TreeNode *child;
	if (loc->left != NULL)
		child = loc->left;
	else
		child = loc->right;
	if (par == NULL)
	{
		root = child;
	}
	else
	{
		if (loc == par->left)
			par->left = child;
		else
			par->right = child;
	}
}

/*
* Case C
*/
void BST::case_c(TreeNode *par, TreeNode *loc)
{
	TreeNode *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr = loc->right;
	while (ptr->left != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = ptrsave;
	if (suc->left == NULL && suc->right == NULL)
		case_a(parsuc, suc);
	else
		case_b(parsuc, suc);
	if (par == NULL)
	{
		root = suc;
	}
	else
	{
		if (loc == par->left)
			par->left = suc;
		else
			par->right = suc;
	}
	suc->left = loc->left;
	suc->right = loc->right;
}

/*
* Pre Order Traversal
*/
void BST::preorder(TreeNode *ptr)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		cout << ptr->val << "  ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
/*
* In Order Traversal
*/
void BST::inorder(TreeNode *ptr)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inorder(ptr->left);
		cout << ptr->val << "  ";
		inorder(ptr->right);
	}
}

/*
* Postorder Traversal
*/
void BST::postorder(TreeNode *ptr)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->val << "  ";
	}
}

/*
* Display Tree Structure
*/
void BST::display(TreeNode *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->val;
		display(ptr->left, level + 1);
	}
}

TreeNode* BST::get_root()
{
	if (root != NULL)
	{
		cout << root->val << endl;
	}
	return root;
}

void BST::add_elements(int* values, int arr_len)
{
	for(int i = 0; i < arr_len; i++)
	{
		TreeNode *temp;
		temp = new TreeNode;
		temp->val = values[i];
		insert(root, temp);
	}
}

void main_binary_tree_v1()
{
	cout << "test start\n" << endl;

	BST bst;
	int values[] = { 5, 4, 2, 7, 6 };
	int arr_len = (sizeof(values) / sizeof(*values));

	//start from here 
	bst.add_elements(values, arr_len);

	TreeNode *root;
	root = bst.get_root();
	bst.display(root, 1);


	cout << "\ntest done" << endl;
	system("pause");

}

/*create binary tree past*/
void main_binary_tree()
{
	cout << "test start\n" << endl;

	BST bst;
	TreeNode *temp;
	TreeNode *root;

	root = bst.get_root();

	temp = new TreeNode;
	temp->val = 5;
	bst.insert(root, temp);

	temp = new TreeNode;
	temp->val = 4;
	root = bst.get_root();
	bst.insert(root, temp);
	temp = new TreeNode;
	temp->val = 3;
	bst.insert(root, temp);
	temp = new TreeNode;
	temp->val = 6;
	bst.insert(root, temp);
	temp = new TreeNode;
	temp->val = 7;
	bst.insert(root, temp);

	bst.display(root, 1);

	cout << "\ntest done" << endl;
	system("pause");

}


void main_test()
{
	int choice, num;
	BST bst;
	TreeNode *temp;

	TreeNode *root;
	root = bst.get_root();

	while (1)
	{
		cout << "-----------------" << endl;
		cout << "Operations on BST" << endl;
		cout << "-----------------" << endl;
		cout << "1.Insert Element " << endl;
		cout << "2.Delete Element " << endl;
		cout << "3.Inorder Traversal" << endl;
		cout << "4.Preorder Traversal" << endl;
		cout << "5.Postorder Traversal" << endl;
		cout << "6.Display" << endl;
		cout << "7.Quit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			temp = new TreeNode;
			cout << "Enter the number to be inserted : ";
			cin >> temp->val;
			bst.insert(root, temp);
			break;
		case 2:
			if (root == NULL)
			{
				cout << "Tree is empty, nothing to delete" << endl;
				continue;
			}
			cout << "Enter the number to be deleted : ";
			cin >> num;
			bst.del(num);
			break;
		case 3:
			cout << "Inorder Traversal of BST:" << endl;
			bst.inorder(root);
			cout << endl;
			break;
		case 4:
			cout << "Preorder Traversal of BST:" << endl;
			bst.preorder(root);
			cout << endl;
			break;
		case 5:
			cout << "Postorder Traversal of BST:" << endl;
			bst.postorder(root);
			cout << endl;
			break;
		case 6:
			cout << "Display BST:" << endl;
			bst.display(root, 1);
			cout << endl;
			break;
		case 7:
			exit(1);
		default:
			cout << "Wrong choice" << endl;
		}
	}
}
