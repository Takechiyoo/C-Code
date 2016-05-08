#include <iostream>

using namespace std;

class Solution
{
public:
    int ways;
    int climbStairs(int n)
    {
        ways = 0;
        climbWays(n);
        return ways;
    }
    int climbTest(int n)
    {
        if(n < 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        return climbTest(n-1) + climbTest(n-2);
    }
    void climbWays(int n)
    {
        if(n < 0)
            return;
        if(n == 0)
        {
            ways++;
            return;
        }
        climbWays(n-1);
        if(n >= 2)
            climbWays(n-2);
    }
};

int main()
{
    Solution s;
    int n;
    cout << "Input n:" << endl;
    cin >> n;

    cout << s.climbTest(n) << endl;
    cout << s.climbStairs(n) << endl;
    cout << "Hello world!" << endl;
    return 0;
}

/*
class Solution {
public:
    int climbStairs(int n){
    if(n <= 0) return 0;
    int stairs[] = {1,2};
    for(int i = 2;i < n;i++){
        stairs[i%2] = stairs[0]+stairs[1];
    }

    return n % 2 == 0 ? stairs[1]:stairs[0];
}
};
*/
