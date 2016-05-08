#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int first, int mid, int last)
{
	vector<int> temp;
	int i = first, j = mid + 1;
	for (int i = 0; i < nums.size(); i++)
		temp.push_back(nums[i]);
	int cur = first;
	while (i <= mid && j <= last)
	{
		if (temp[i] <= temp[j])
			nums[cur++] = temp[i++];
		else
			nums[cur++] = temp[j++];
		cout << "i:" << i  << " " << "j:" << j << endl;
		
	}
	while (i <= mid)
		nums[cur++] = temp[i++];
}

void mergeSort(vector<int>& nums, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		cout << mid << endl;
		mergeSort(nums, first, mid);
		mergeSort(nums, mid + 1, last);
		merge(nums, first, mid, last);
	}
	
}
