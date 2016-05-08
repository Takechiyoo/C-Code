#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int sum = nums[0], preSum = nums[0];
		int length = nums.size();
		int j = 0;
		while (nums[j] <= 0 && j < length)
		{
			if (nums[j] > sum)
				sum = preSum = nums[j];
			j++;
		}
		if (j < length)
			sum = preSum = nums[j];
		else
			return sum;
		for (int i = j + 1; i < length; i++)
		{
			if (sum + nums[i] > preSum)
			{
				sum += nums[i];
				preSum = sum;
				continue;
			}
			if (sum + nums[i] < 0)
				sum = 0;
			else
				sum += nums[i];
		}
		return sum > preSum ? sum : preSum;
	}
};
