#pragma once


//extern struct TreeNode *root;
extern void main_binary_tree();
extern void main_binary_tree_v1();


/*
* TreeNode Declaration
*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	//*TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
* Class Declaration
*/
class BST
{
private:

public:
	struct TreeNode *root;

	void find(int, TreeNode **, TreeNode **);
	void insert(TreeNode *, TreeNode *);
	void del(int);
	void case_a(TreeNode *, TreeNode *);
	void case_b(TreeNode *, TreeNode *);
	void case_c(TreeNode *, TreeNode *);
	void preorder(TreeNode *);
	void inorder(TreeNode *);
	void postorder(TreeNode *);
	void display(TreeNode *, int); 
	TreeNode* get_root();
	void add_elements(int* values, int arr_len);
	BST()
	{
		root = NULL;
	}

};

