#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max_length = 0;
        map<char, int> mapstring;
        map<char, int> ::iterator it;
        int temp_length = 0;
        for(int i = 0, j = 0; i < s.length(); i++)
        {
            it = mapstring.find(s[i]);
            if(it == mapstring.end())
            {
                mapstring.insert(pair<char, int>(s[i], 1));
                temp_length++;
                continue;
            }
            if(temp_length > max_length)
                max_length = temp_length;
            for(j; j < i; j++)
            {
                if(s[j] != s[i])
                {
                    mapstring.erase(s[j]);
                    temp_length--;
                }
                else
                {
                    j++;
                    break;
                }
            }

        }
        if(temp_length > max_length)
            max_length = temp_length;
        return max_length;
    }
};


int main()
{
    string ss;
    cout << "Please input the string:" << endl;
    cin >> ss;
    Solution s;
    cout << "The Longest Substring size is:" << s.lengthOfLongestSubstring(ss) << endl;
    cout << "Hello world!" << endl;
    return 0;
}


/*
int lengthOfLongestSubstring(string s) {
    if(s.size()<2){
        return s.size();
    }

    int longest=0;
    int tempCount=0;
    unordered_set<char> keys;
    auto beginindexIt =s.begin();
    auto it = beginindexIt;
    while(it!=s.end()){
        if(s.end()-it+tempCount <=longest){
            return longest;
        }
        if(keys.find(*it) == keys.end()){
            keys.insert(*it);
            tempCount++;
            if(tempCount>longest){
                longest = tempCount;
            }
        }else{
           for(beginindexIt;beginindexIt<it;beginindexIt++){
               if(*beginindexIt!=*it){
                   keys.erase(*beginindexIt);
                   tempCount--;
               }else{
                   beginindexIt++;
                   break;
               }
           }
        }
        it++;
    }
    return longest;
}
*/
