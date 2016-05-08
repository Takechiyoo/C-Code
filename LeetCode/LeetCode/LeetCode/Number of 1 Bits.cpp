#include <iostream>
#include <stdint.h>

using namespace std;

/*
Write a function that takes an unsigned integer and returns the number of ��1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ��11' has binary representation 00000000000000000000000000001011, so the function should return 3.

һ����uint32_t���ֵľ��е�ţ�����ò�ƺ���ͨ��intʲô��Ҳû��ʲô̫��Ĳ�ͬ��
�������ʵ�����ԭ����ߵ���ΰ�һ��������ʾ�ɶ���������һ���£�ֱ��ʵ���Ǹ��㷨�����Ϳ����ˡ�
*/
class Solution{
public:
	int hammingWeight(uint32_t n) {
		uint32_t temp = n;
		int count = 0;
		while (temp)
		{
			count += temp % 2;
			temp = temp / 2;
		}
		return count;
	}
};
