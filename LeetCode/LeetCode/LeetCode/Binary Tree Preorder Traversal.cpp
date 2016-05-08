#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
先序遍历 概念一定要搞清楚，容易和层次遍历弄混
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode *temp = s.top();
			s.pop();
			result.push_back(temp->val);
			if (temp->right)
				s.push(temp->right);
			if (temp->left)
				s.push(temp->left);
		}
		return result;
	}
};