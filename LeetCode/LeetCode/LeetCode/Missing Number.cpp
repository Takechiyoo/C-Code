#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/*����������ֽ���˼·��
	1����������Ĳ������ķ������ǳ���������û���뵽
	2������bitset�� ��λ�ķ���������������ڱ�������Ͽ���������һ��ʼ��ֱ���뵽���������ͬʱҲ������˼·
	3��������� ��Ϊ��0-nֻȱʧһ�����֣���������0 �� n-1�ĺ�Ȼ������ʵ�ʵĺ�һ����͵õ��˽�����������ַ��������������
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