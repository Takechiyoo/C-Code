#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix)
    {
        auto result = matrix;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                result[j][matrix.size() - i - 1] = matrix[i][j];
            }
        }
        matrix = result;
    }
};

int main()
{
    cout << "hello world!" << endl;
}
