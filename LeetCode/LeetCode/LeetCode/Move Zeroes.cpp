#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	void moveZeroes(vector<int>& nums){
		vector<int>::iterator it;
		int count = 0;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			if (*it == 0)
			{
				count++;
				continue;
			}
			*(it - count) = *it;
		}
		for (it = nums.end() - count; it != nums.end(); it++)
			*it = 0;
	}
};
