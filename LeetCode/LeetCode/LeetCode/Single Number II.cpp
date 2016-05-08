#include <iostream>
#include <vector>

using namespace std;

//Given an array of integers, every element appears three times except for one. Find that single one.
/*
Idea is simple, since all numbers appear multiple of 3 times except one, 
for 32 bit integer, you sum over each bit, if sum on any bit is NOT divided by 3 exactly, 
the single number must have that bit on .
*/

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int res = 0;
		int k = 0;
		int length = nums.size();
		while (k < 32){
			int temp = 0;
			for (int i = 0; i < length; i++){
				temp += ((nums[i] >> k) & 1);
			}
			if (temp % 3 != 0){
				res = res | (1 << k);    //如果该数在某一位上值为0，那么%3也是0，0左移k位也没有影响
			}
			k++;
		}
		return res;
	}
};