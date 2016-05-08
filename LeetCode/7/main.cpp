#include <iostream>

using namespace std;

string revert(int n)
{
    string m = "0123456789ABCDEFGH";
    string temp = "";
    string result = "";
    //int a;
    int b;
    while(true)
    {
        b = n % 18;
        n = n / 18;
        temp += m[b];
        if(n < 18)
        {
            temp += m[n];
            break;
        }
    }
    for(int i = temp.size()-1; i >= 0; i--)
        result += temp[i];
    return result;
}

int main()
{
    int a;
    cout << "Please input the number:" << endl;
    cin >> a;
    cout << revert(a) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
