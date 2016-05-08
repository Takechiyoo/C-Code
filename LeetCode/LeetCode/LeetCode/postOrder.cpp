#include <iostream>
#include <stack>
#include <string>

using namespace std;

void helper_post(const string& preOrder, const string& inOrder, int first, int last, stack<char>& s)   // find the root of child tree
{
	if (first > last)
		return;
	int minIndex = preOrder.size();
	int index = first;
	for (int i = first; i <= last; i++)
	{
		int tempIndex = preOrder.find(inOrder[i]);
		//cout << index << endl;
		if (tempIndex < minIndex)
		{
			minIndex = tempIndex;
			index = i;
		}
	}
	s.push(preOrder[minIndex]);   // push the root
	helper_post(preOrder, inOrder, index + 1, last, s);   // find the root of the right child tree
	helper_post(preOrder, inOrder, first, index - 1, s);  // find the root of the left child tree
}

void post_order(string preOrder, string inOrder)
{
	if (!preOrder.size() && !inOrder.size())
		return;
	stack<char> s;
	//s.push(preOrder[0]);
	int lastIndex = inOrder.size() - 1;
	//int mid = inOrder.find(preOrder[0]);
	helper_post(preOrder, inOrder, 0, lastIndex, s);
	//helper_post(preOrder, inOrder, 0, mid - 1, s);
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
