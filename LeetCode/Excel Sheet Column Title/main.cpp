#include <iostream>
#include <vector>

using namespace std;

/*
*联想到十进制和二进制的转换
*/
class Solution
{
public:
    string convertToTitle(int n)
    {
        if(n == 0)
            return "";
        string result;
        string ampha = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        vector<int> remainder;
        int temp = n;
        int sum = 0;
        while(true)
        {
            remainder.push_back(temp % 26);
            if(temp%26 == 0)
                temp = int(temp / 26) - 1;
            else
                temp = int(temp / 26);
            sum++;
            if(temp == 0) break;
        }
        for(int i = sum - 1; i >= 0; i--)
            result += ampha[remainder[i]];
        return result;
    }
};



int main()
{
    Solution s;
    cout << s.convertToTitle(26*26+26+1) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
