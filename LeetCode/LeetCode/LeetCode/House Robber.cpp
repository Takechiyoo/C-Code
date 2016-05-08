#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int rob(vector<int>& nums)
	{
		int length = nums.size();
		vector<int> r(length + 1, 0);   // Rob the house.  The maximum profit we get with robbing the i house.
		vector<int> f(length + 1, 0);   // Forgive the house. 
		for (int i = 1; i < length + 1; i++)
		{
			r[i] = max(r[i - 1], f[i - 1] + nums[i - 1]);
			f[i] = max(f[i - 1], r[i - 1]);    // Actually, f[i - 1] is always less or equal than r[i - 1].
		}
		return r[length];
	}
	/*
	int rob(vector<int>& nums) {
		int n = nums.size(), pre = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			int temp = max(pre + nums[i], cur);
			pre = cur;
			cur = temp;
		}
		return cur;
	*/
};
