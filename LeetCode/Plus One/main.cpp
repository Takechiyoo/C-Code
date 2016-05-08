#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        stack<int> stk;
        int temp, length;
        length = digits.size();
        if(length == 0)
        {
            digits.push_back(1);
            return digits;
        }
        temp = 1;
        for(int i = length-1; i >= 0; i--)
        {
            stk.push((digits[i]+temp)%10);
            temp = (digits[i] + temp) / 10;
        }
        if(temp != 0)
            stk.push(temp);
        digits.clear();
        while(!stk.empty())
        {
            temp = stk.top();
            stk.pop();
            digits.push_back(temp);
        }
        return digits;
    }
};

int main()
{
    vector<int> v;
    v.push_back(0);
    Solution s;
    s.plusOne(v);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " " << endl;
    cout << endl;
    cout << "Hello world!" << endl;
    return 0;
}

/*
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;

        for(int i=digits.size()-1; i >= 0 && carry; i--) {
            carry = (++digits[i]%=10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
*/
