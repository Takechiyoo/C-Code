#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>


/*
 * 这是一道典型的动态规划的问题，可惜我没有看出来，一开始的解题思路就有问题，受教了
 * https://leetcode.com/discuss/71354/share-my-thinking-process
*/
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int buy(INT_MIN), sell(0), pre_sell(0), pre_buy;
		for (int price : prices) {
			pre_buy = buy;
			buy = max(pre_sell - price, buy);
			pre_sell = sell;
			sell = max(pre_buy + price, sell);
		}
		return sell;
	}
};

int main()
{
	int i = 0;
	while (i < 6)
	{
		i++;
		int v = rand() % 10 + 1;
		cout << v << " ";
	}
	cout << endl;

	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 10);
	int seed;
	cout << "Please input the seed" << endl;
	cin >> seed;
	while (i < 16)
	{
		i++;
		generator.seed(seed + i);
		int dice_roll = distribution(generator);
		cout << dice_roll << " ";
	}
	cout << endl;
	return 0;
}