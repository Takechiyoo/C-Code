#include <iostream>
#include <stdint.h>

using namespace std;

/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

一看到uint32_t这种的就有点慌，不过貌似和普通的int什么的也没有什么太多的不同。
这个题其实和组成原理里边的如何把一个整数表示成二进制数是一回事，直接实现那个算法基本就可以了。
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
