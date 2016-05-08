#include <iostream>
#include <hash_map>
#include <vector>

using namespace std;

class Solution {
private:
	hash_map<int, int> data;
public:
	bool containsDuplicate(vector<int>& nums) {
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); it++) {
			if (data[*it])
				return true;
			else
				data[*it] = 1;
		}
		return false;
	}
};
