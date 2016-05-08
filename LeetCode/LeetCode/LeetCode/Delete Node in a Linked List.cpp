#include <iostream>

using namespace std;

/*
最开始的想法真是蠢爆了，竟然还用了循环，真是忘了什么叫链表了。 不加判断的话只需要两行代码就可以了，不知道为什么这么短的代码才战胜9%的人
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
public:
	void deleteNode(ListNode* node)
	{
		/*while (node)
		{
			node->val = node->next->val;
			if (node->next->next == NULL)
			{
				node->next = NULL;
			}
			node = node->next;
		}*/
		if (node->next == NULL || node == NULL)
			return;
		node->val = node->next->val;
		node->next = node->next->next;
	}
};
