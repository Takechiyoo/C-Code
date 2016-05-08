#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int findMin(vector<int>& nums){
		int length = nums.size();
		int minNumber = nums[0] < nums[length - 1] ? nums[0] : nums[length - 1];
		for (int i = 0, j = length - 1; i < j; i++, j--)
		{
			if (nums[i + 1] < nums[i])
			{
				minNumber = nums[i + 1];
				break;
			}
			if (nums[j - 1] > nums[j])
			{
				minNumber = nums[j];
				break;
			}
		}
		return minNumber;
	}
	/**
	int findMin(vector<int>& nums){
		int l = 0, r = nums.size() - 1;
		while(l < r)
		{
			int mid = (r - 1) / 2 + l;
			if (nums[mid] < nums[r])
				r = mid
			else
				l = mid + 1
		}
		return nums[l];
	}
	*/
};