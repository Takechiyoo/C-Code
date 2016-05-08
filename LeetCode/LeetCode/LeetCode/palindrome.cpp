#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxLength(int i, int j, string s)
{
	if (i == j)
		return 1;
	if (i > j)
		return 0;
	if (s[i] == s[j])
		return 2 + maxLength(i + 1, j - 1, s);
	int pre = maxLength(i, j - 1, s);
	int post = maxLength(i + 1, j, s);
	return pre > post ? pre : post;
}

int maxLengths(string s)
{
	int n = s.length();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	//int[][] dp = new int[n][n];
	//for (int i = n - 1; i <= 0; i--)
		//for (int j = i; i <= n - 1; j++)
			//dp[i][j] = j - i;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j <= n - 1; j++)
		{
			if (s[i] == s[j])
			{
				if (i + 1 <= j - 1)
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = 0;
			}
			else
			{
				//dp[i][j] = Math.min(1 + dp[i][j - 1], 1 + dp[i + 1][j]);
				dp[i][j] = 1 + dp[i][j - 1] < dp[i + 1][j] + 1 ? 1 + dp[i][j - 1] : dp[i + 1][j] + 1;
			}
		}
	}
	return dp[0][n - 1];
}

int maxLength(string s)
{
	int n = s.size();
	vector<int> result(n + 1, 0);
	return 0;
}
