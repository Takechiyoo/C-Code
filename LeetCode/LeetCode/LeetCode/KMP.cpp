#include <iostream>
#include <vector>

using namespace std;

vector<int> computePrefix(string p)
{
	int m = p.length();
	vector<int> pi(m+1, 0);

	int k = 0;
	for (int q = 1; q < m; q++)
	{
		while (k > 0 && p[k] != p[q])
			k = pi[k];
		if (p[k] == p[q])
			k++;
		pi[q + 1] = k;
	}
	return pi;
}

void KMP(string original, string pattern, vector<int> computePrefix(string))
{
	int j = 0;
	vector<int> pi = computePrefix(pattern);
	for (int i = 0; i < original.size(); i++)
	{
		while (j > 0 && original[i] != pattern[j])
			j = pi[j];
		if (original[i] == pattern[j])	j++;
		if (j == pattern.length())
		{
			cout << "find at position " << (i - j + 1) << endl;
			j = pi[j];
		}
	}
}
