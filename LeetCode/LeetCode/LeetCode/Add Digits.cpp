#include<iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
	/*
	int addDigits(int num)
	{
		if (num == 0)
			return num;
		else if ((num % 9) == 0)
			return 9;
		else
			return num % 9;
	}
	*/
	int addDigits(int num)
	{
		if (num < 10)
			return num;
		int sum = 0;
		stringstream ss;
		ss << num;
		string numString;
		ss >> numString;
		for (auto c : numString)
		{
			int temp;
			stringstream stream;
			stream << c;
			stream >> temp;
			sum += temp;
		}
		return addDigits(sum);
	}
};
/*
int main()
{
	Solution s;
	int num;
	cout << "Please input a non negtive number!" << endl;
	while (cin >> num)
	{
		cout << s.addDigits(num) << endl;
		cout << "Please input a non negtive number!" << endl;
	}
	cout << "hello world" << endl;
	return 0;
}
*/