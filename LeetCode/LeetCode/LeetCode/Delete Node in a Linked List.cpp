#include <iostream>

using namespace std;

/*
�ʼ���뷨���Ǵ����ˣ���Ȼ������ѭ������������ʲô�������ˡ� �����жϵĻ�ֻ��Ҫ���д���Ϳ����ˣ���֪��Ϊʲô��ô�̵Ĵ����սʤ9%����
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
