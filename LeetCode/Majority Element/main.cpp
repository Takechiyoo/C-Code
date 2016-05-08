#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &num)
    {
        map<int, int> maplive;
        map<int, int>::iterator it;
        int m = num.size() / 2;
        for(int i = 0; i < num.size(); i++)
        {
            it = maplive.find(num[i]);
            if(it == maplive.end())
            {
                maplive.insert(pair<int, int>(num[i], 1));
                if(1 > m)
                    return num[i];
            }
            else
            {
                it->second++;
                if(it->second > m)
                    return num[i];
            }
        }
        return 0;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
/*
public class Solution {
public int majorityElement(int[] num) {
    Arrays.sort(num);
    return num[num.length / 2];
}}
*/
