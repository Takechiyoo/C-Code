#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        if(grid.empty())
            return 0;
        for(int i = 1; i < grid[0].size(); i++)
            grid[0][i] += grid[0][i-1];
        for(int j = 1; j < grid.size(); j++)
            grid[j][0] += grid[j-1][0];
        for(int j = 1; j < grid.size(); j++)
        {
             for(int i = 1; i < grid[j].size(); i++)
             {
                 int minValue;
                 minValue = grid[j-1][i] <= grid[j][i-1] ? grid[j-1][i] : grid[j][i-1];
                 grid[j][i] += minValue;
             }
        }
        int n = grid[grid.size()-1].size();
        return grid[grid.size()-1][n - 1];
    }
};

int main()
{
    vector<vector<int> > grid;
    vector<int> a, b;
    a.push_back(1);
    b.push_back(2);
    grid.push_back(a);
    grid.push_back(b);
    Solution s;
    cout << s.minPathSum(grid) << endl;

    cout << "Hello world!" << endl;
    return 0;
}
