#include <iostream>
#include <vector>

using namespace std;
/*
�����������ǰһ����˼·�� ����Ʊһֱ�߸ߵ�ʱ��ͳֹɣ�һ����Ʊ�ߵ����ߵ͵�ǰһ��������Ȼ���ظ������õ���һ�������ġ�
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		int low, previous, length;
		length = prices.size();
		if (length < 2)
			return 0;
		low = prices[0];
		previous = prices[0];
		for (int i = 1; i < length; i++)
		{
			if (previous > prices[i])
			{
				profit += previous - low;
				low = prices[i];
				previous = prices[i];
			}
			previous = prices[i];
		}
		profit += previous - low;
		return profit;
	}
};
