#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int len = s.length() - 1;
        int result = 0;
        for(int i = 0; i < s.length(); i++)
        {
            cout <<((s[i] - 64) * pow(26, len)) << endl;
            result = (s[i] - 64) * pow(26, len);
            len--;
            cout << "result is:" << result << endl;
        }
        return result;
    }
};

int main()
{
    string s = "AA";
    Solution so;
    cout << so.titleToNumber(s) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
