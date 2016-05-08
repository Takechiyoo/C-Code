#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution{
public:
	bool hasCycle(ListNode *head)
	{
		if (head == NULL)	return false;
		ListNode *temp = head;
		while (true)
		{
			if (temp->next && temp->next->next)
				temp = temp->next->next;
			else
				return false;
			head = head->next;
			if (head == temp)
				return true;
		}
	}
};
*/
/*if the list has got a loop, then its reversed version must have got the same head pointer as its self*/
class Solution {
public:
ListNode* reverseList(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* follow = NULL;
	while (head)
	{
		follow = head->next;
		head->next = prev;
		prev = head;
		head = follow;
	}
	return prev;
}

	bool hasCycle(ListNode *head)
	{
		ListNode* rev = reverseList(head);
		while (rev)
		{
			cout << rev->val << endl;
			rev = rev->next;
		}
		if (head && head->next && rev == head)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	ListNode *head = new ListNode(10);
	ListNode *p1 = new ListNode(8);
	ListNode *p2 = new ListNode(7);
	head->next = p1;
	p1->next = p2;
	p2->next = p1;
	Solution s;
	s.hasCycle(head);
	return 0;
}