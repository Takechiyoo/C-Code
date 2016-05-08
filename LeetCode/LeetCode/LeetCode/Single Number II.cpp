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
				res = res | (1 << k);    //���������ĳһλ��ֵΪ0����ô%3Ҳ��0��0����kλҲû��Ӱ��
			}
			k++;
		}
		return res;
	}
};