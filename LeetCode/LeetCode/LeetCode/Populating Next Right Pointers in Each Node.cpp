#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if (root == NULL)
			return;
		root->next = NULL;
		helpConnect(root);
	}

	void helpConnect(TreeLinkNode *root)
	{
		if (root == NULL)
			return;
		if (root->left)
			root->left->next = root->right;
		if (root->right)
		{
			if (root->next)
				root->right->next = root->next->left;
			else
				root->right->next = NULL;
		}
		if (root->left)
			helpConnect(root->left);
		if (root->right)
			helpConnect(root->right);
	}
};

/*
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return;
			// Link root's children
		root->left->next = root->right;
		if (root->next != NULL)
			root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
	}
};*/
