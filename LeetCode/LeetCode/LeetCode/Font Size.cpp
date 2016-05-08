#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool validFont(vector<int>& para, int n, int p, int w, int h, int size)
{
	int linesPerPage = floor(1.0 * h / size);
	int numPerLine = floor(1.0 * w / size);
	int sumLines = p * linesPerPage;
	for (int i = 0; i < para.size(); i++)
	{
		sumLines -= ceil(1.0 * para[i] / numPerLine);
		if (sumLines < 0) return false;
		if (sumLines == 0 && i == n - 1) return true;
	}
	return true;
}
/*
int main()
{
	int testNum;
	int n, p, w, h;
	cin >> testNum;
	while (testNum)
	{
		testNum--;
		cin >> n >> p >> w >> h;
		vector<int> para;
		int a;
		double sum = 0;
		while (n)
		{
			n--;
			cin >> a;
			sum += a;
			para.push_back(a);
		}
		int maxSize = ceil(sqrt(1.0 * p * w * h / sum));
		while (maxSize)
		{
			if (validFont(para, n, p, w, h, maxSize))
				break;
			maxSize--;
		}
		cout << maxSize << endl;
	}
}
*/