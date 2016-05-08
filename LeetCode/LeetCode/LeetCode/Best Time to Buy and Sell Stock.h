#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int low, profit;
		int length = prices.size();

		if (length < 2)	return 0;
		low = prices[0];
		profit = 0;
		for (int i = 1; i < length; i++)
			if (prices[i] < low)
				low = prices[i];
			else if (prices[i] - low > profit)
				profit = prices[i] - low;
		return profit;
	}
};