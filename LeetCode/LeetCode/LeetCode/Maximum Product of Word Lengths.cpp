#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int maxProduct(vector<string>& words) {
		vector<int> mask;
		int length = words.size();
		for (int i = 0; i < length; i++)
		{
			int temp = 0;
			for (int j = 0; j < words[i].length(); j++)
				temp |= (1 << words[i][j] - 'a');
			mask.push_back(temp);
		}

		int maxProduct = 0;
		for (int i = 0; i < length; i++)
			for (int j = i + 1; j < length; j++)
			{
				if ((mask[i] & mask[j]) == 0 && words[i].length() * words[j].length() > maxProduct)
					maxProduct = words[i].length() * words[j].length();
			}
		return maxProduct;
	}
};