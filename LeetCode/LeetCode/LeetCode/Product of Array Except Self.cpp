#include <iostream>
#include <vector>

using namespace std;

/*The idea is simply. 
The product basically is calculated using the numbers before the current number and the numbers after the current number.
Thus, we can scan the array twice. First, we calcuate the running product of the part before the current number. 
Second, we calculate the running product of the part after the current number through scanning from the end of the array*/

class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		vector<int> result;
		int length = nums.size();
		int before = 1;
		for (int i = 0; i < length; i++)
		{
			result.push_back(before);
			before *= nums[i];
		}
		int after = 1;
		for (int i = length - 1; i >= 0; i--)
		{
			result[i] *= after;
			after *= nums[i];
		}
		return result;
	}
};