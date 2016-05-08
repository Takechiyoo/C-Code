#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if(s.size() == 0)   return true;
        string s1 = "([{";
        string s2 = ")]}";
        stack<char> ss;

        for(int i = 0; i < s.size(); i++)
        {
            if(ss.empty())
            {
                if(s2.find(s[i]) != -1) return false;
                ss.push(s[i]);
                continue;
            }
            if(s1.find(s[i]) != -1)       //第i位出现在s1中
            {
                ss.push(s[i]);
                continue;
            }
            int index = s2.find(s[i]);
            if(index != -1)
            {
                if(ss.top() != s1[index])   return false;
                ss.pop();
                continue;
            }
        }
        if(ss.empty())  return true;

        return false;
    }
};

int main()
{
    Solution s;
    string test = "({)}{}";
    if(s.isValid(test))
        cout << "Success!" << endl;
    cout << "hello world" << endl;
}
