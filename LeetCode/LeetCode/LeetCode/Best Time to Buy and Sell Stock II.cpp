#include <iostream>
#include <vector>

using namespace std;
/*
这个题借鉴的是前一个的思路。 当股票一直走高的时候就持股，一旦股票走低在走低的前一刻卖掉，然后重复。最后得到的一定是最大的。
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
