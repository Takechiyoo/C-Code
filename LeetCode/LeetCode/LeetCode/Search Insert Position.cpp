#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		if (nums.size() == 0)
			return -1;
		return binSearch(nums, 0, nums.size() - 1, target);
	}
	int binSearch(vector<int>& nums, int low, int high, int target)
	{
		if (low >= high)  /*有可能会出现low 大于 high的情况 比如[1, 3] target = 0*/
		{
			if (nums[low] == target)
				return low;
			else if (nums[low] > target)
				return low;
			else
				return low + 1;
		}
		if (nums[(low + high) / 2] == target)
			return (low + high) / 2;
		else if (nums[(low + high) / 2] > target)
			return binSearch(nums, low, (low + high) / 2 - 1, target);
		else
			return binSearch(nums, (low + high) / 2 + 1, high, target);
	}
};

