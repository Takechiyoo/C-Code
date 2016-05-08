#include <iostream>

using namespace std;

class Solution
{
public:
    int trailingZeros(int n)
    {
        int res = 0;
        while(n)
        {
            n /= 5;
            res += n;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n;
    cout << "input the n:" <<endl;
    cin >> n;
    cout << "The result is:" << s.trailingZeros(n) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
