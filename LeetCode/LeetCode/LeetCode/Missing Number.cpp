#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/*这道题有三种解题思路：
	1、下面给出的采用异或的方法，非常聪明，我没有想到
	2、采用bitset的 置位的方法。这个方法我在编程珠玑上看过，所以一开始就直接想到这个方法，同时也抑制了思路
	3、求和做差 因为从0-n只缺失一个数字，因此先求从0 到 n-1的和然后再求实际的和一做差就得到了结果。不过这种方法存在溢出现象
*/

class Solution
{
public:
	/*
	int missingNumber(vector<int>& nums)
	{
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
			result ^= nums[i] ^ (i + 1);
		return result;
	}
	*/
	int missingNumber(vector<int>& nums) {
		int length = nums.size();
		bitset<2147483647> b;
		for (int i = 0; i < length; i++)
			b.set(nums[i], 1);
		for (int i = 0; i < length; i++)
		{
			if (!b.test(i))
				return i;
		}
	}
};