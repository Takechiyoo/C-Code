#include <iostream>

using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        int i, j, temp, sum;
        i = 0;
        sum = 0;
        for( i = 0; i+sum < n; i++)
        {
            temp = i + sum + 1;
            for(j = temp; j < n; j++)
            {
                if(A[i] == A[j])
                {
                    sum++;
                    continue;
                }
                break;
            }
            if(j < n)
                A[i+1] = A[j];
        }
        for(i = 0; i < n-sum; i++)
            cout << A[i] << " ";
        cout << endl;
        return n-sum;
    }
};

int main()
{
    int A[] = {1, 1, 2, 2, 3, 4, 5, 5, 6};
    Solution s;
    cout << s.removeDuplicates(A, 9) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
