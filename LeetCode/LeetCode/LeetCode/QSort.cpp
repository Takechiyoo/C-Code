#include <iostream>
#include <vector>

using namespace std;

/*
int partition(vector<int> &nums, int start, int r)
{
	int x = nums[r];
	int i = start;
	int j = r - 1;
	while (i < j)
	{
		while (nums[i] <= x && i < j) i++;
		while (nums[j] > x && j > i) j--;
		if (i < j)
		{
			int temp = nums[j];
			nums[j] = nums[i];
			nums[i] = temp;
		}
	}
	if (i < r && nums[i] > x)
	{
		nums[r] = nums[i];
		nums[i] = x;
		cout << x << ":" << i << endl;
		return i;
	}
	cout << x << ":" << r << endl;
	return r;
}
*/

int partition(vector<int> &nums, int l, int r)
{
	int i = l, j = r;
	int x = nums[l];
	while (i < j)
	{
		while (i < j && nums[j] >= x)
			j--;
		if (i < j)
		{
			nums[i] = nums[j];
			i++;
		}
		while (i < j && nums[i] < x)
			i++;
		if (i < j)
		{
			nums[j] = nums[i];
			j--;
		}
	}
	nums[i] = x;
	return i;
}

void quickSort(vector<int> & nums, int start, int r)
{
	if (start < r)
	{
		int index = partition(nums, start, r);
		quickSort(nums, start, index - 1);
		quickSort(nums, index + 1, r);
	}
}
