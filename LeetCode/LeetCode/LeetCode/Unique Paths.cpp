#include <iostream>
#include <vector>

using namespace std;

/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 * How many possible unique paths are there?
 * This is a dynamic programming problem.
*/
class Solution{
public:
	int uniquePaths(int m, int n)
	{
		if (m == 0 || n == 0)
			return 0;
		int result[100][100];
		//Initialize the matrix
		for (int i = 0; i < 100; i++)
		{
			result[0][i] = 1;
			result[i][0] = 1;
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
				result[i][j] = result[i - 1][j] + result[i][j - 1];
		}
		return result[m - 1][n - 1];
	}
};
