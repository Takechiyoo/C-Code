#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> s;
		TreeNode *temp = root;
		while (true)
		{
			while (temp)
			{
				s.push(temp);
				temp = temp->left;
			}
			if (s.empty())
				return result;
			result.push_back(s.top()->val);
			temp = s.top()->right;
			s.pop();
		}
	}
};

