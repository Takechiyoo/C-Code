#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        stack<char> temp;
        int up = 0;
        int aLength, bLength;
        aLength = a.length();
        bLength = b.length();
        int shortLength = min(aLength, bLength);
        for(int i = aLength-1, j = bLength - 1; i >= 0 && j >= 0; i--, j--)
        {
            temp.push((a[i] - '0' + b[j] - '0' + up) % 2 + '0');
            up = (a[i] - '0' + b[j] - '0' + up) / 2;
        }
        if(aLength > bLength)
        {
            int i = aLength - shortLength - 1;
            while(i >= 0)
            {
                temp.push((a[i] - '0' + up) % 2 + '0');
                up = (a[i] - '0' + up) / 2;
                i--;
            }
        }
        else
        {
            int i = bLength - shortLength - 1;
            while(i >= 0)
            {
                temp.push((b[i] - '0' + up) % 2 + '0');
                up = (b[i] - '0' + up) / 2;
                i--;
            }
        }
        if(up != 0)
            temp.push(up+'0');
        while(!temp.empty())
        {
            result += temp.top();
            temp.pop();
        }
        return result;
    }
};

int main()
{
    Solution s;
    string a, b;
    cout << "Please input two binary string:" << endl;
    cin >> a >> b;
    cout << s.addBinary(a, b) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
