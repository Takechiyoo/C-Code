#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int v) : val(v), left(NULL), right(NULL) {}
};

void preTraversal(Node *root)
{
	stack<Node *> s;
	if (root == NULL) return;
	s.push(root);
	while (!s.empty())
	{
		Node* temp = s.top();
		cout << temp->val << endl;
		s.pop();
		if (temp->right)
			s.push(temp->right);
		if (temp->left)
			s.push(temp->left);
	}
}
