/**
 Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 中序遍历 可以得到从小到大的 排列顺序
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution {
public:
	int kthSmallest(TreeNode* root, int k)
	{
		if (root == NULL) return -1;
		vector<int> num;
		inOrderTraversal(root, num, k);
		return num[k - 1];
	}

	void inOrderTraversal(TreeNode* root, vector<int> &num, int k)
	{
		if (root == NULL) return;
		inOrderTraversal(root->left, num, k);
		if (num.size() == k) return;
		num.push_back(root->val);
		inOrderTraversal(root->right, num, k);
	}
};