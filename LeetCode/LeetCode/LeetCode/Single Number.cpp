#include <iostream>
#include <vector>

/*采用异或操作*/

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); it++)
			result ^= *it;
		return result;
	}
};