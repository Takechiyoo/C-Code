#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(char *haystack, char *needle)
    {
        int hLength = 0, nLength = 0;
        int start = 0;
        bool flag = false;
        char *tempD = needle;
        char *tempS = haystack;
        while(*tempS != '\0')
        {
            tempS++;
            hLength++;
        }
        if(hLength == 0)    return -1;
        while(*tempD != '\0')
        {
            tempD++;
            nLength++;
        }
        if(nLength == 0)    return -1;
        if(hLength < nLength)   return -1;
        cout << "source length is:" << hLength << endl;
        cout << "d length is:" << nLength << endl;
        tempD = needle;
        while(*haystack != '\0')
        {
            if(*haystack != *tempD)
            {
                haystack++;
                start++;
                //if(nLength+start > hLength)
                  //  return -1;
                continue;
            }
            tempS = haystack;
            flag = isMatch(tempS, tempD);
            if(flag)
                break;
            start++;
            haystack++;
            tempD = needle;
        }
        if(flag) return start;
        return -1;
    }
    bool isMatch(char *s, char *d)
    {
        int flag;
        while(true)
        {
            if(*s == '\0' && *d != '\0')
            {
                flag = false;
                break;
            }
            if(*s != *d && *d != '\0')
            {
                flag = false;
                break;
            }
            if(*d == '\0')
            {
                flag = true;
                break;
            }
            s++;
            d++;
        }
        return flag;
    }
};

int main()
{
    char *s = "aaaaaaaaa";
    char *d = "g";
    int n = 0;
    Solution ss;
    n = ss.strStr(s, d);
    //char *test;
    //test = d;
    //while(*s != '\0')
      //  n++;
    cout << "The start is:" << n << endl;
    cout << "Hello world!" << endl;
    return 0;
}

class Solution {
public:
    int strStr(char *haystack, char *needle) {
    int llen = strlen(haystack);
    int slen = strlen(needle);

    if (slen == 0) return 0;

    int i = slen -1;
    while (i<llen) {
        while (haystack[i] != needle[slen-1] && i<llen) i++;
        if (i == llen) return -1;

        int j=1;
        for (j; j<slen; j++) {
            if (needle[slen-1-j] != haystack[i-j]) break;
        }
        if (j==slen) return (i-slen+1);
        i++;
    }
    return -1;
}
};
