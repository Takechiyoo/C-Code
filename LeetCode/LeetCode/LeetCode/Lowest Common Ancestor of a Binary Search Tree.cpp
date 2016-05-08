#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//if (root == NULL)
			//return;
		if ((p->val >= root->val && q->val <= root->val) || (p->val <= root->val && q->val >= root->val))
			return root;
		if (p->val > root->val && q->val > root->val)
			lowestCommonAncestor(root->right, p, q);
		else
			lowestCommonAncestor(root->left, p, q);
	}
};