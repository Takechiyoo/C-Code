#include <iostream>

using namespace std;

class Solution
{
public:
    void mergeSortedArray(int A[], int m, int B[], int n)
    {
        int C[m+n];
        int i, j, k = 0;
        for(i = 0, j = 0; i < m && j < n;)
        {
            if(A[i] <= B[j])
            {
                C[k++] = A[i];
                i++;
            }
            else
            {
                C[k++] = B[j];
                j++;
            }
        }
        if(i == m)
        {
            while(j < n)
                C[k++] = B[j++];
        }
        if(j == n)
        {
            while(i < m)
                C[k++] = A[i++];
        }
        for(i = 0; i < m+n; i++)
            A[i] = C[i];
        for(i = 0; i < m+n; i++)
            cout<< A[i] << " ";
        cout << endl;
    }
};

/*从最后一个元素考虑 妙妙妙！
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {

        int a=m-1;
        int b=n-1;
        int i=m+n-1;    // calculate the index of the last element of the merged array

        // go from the back by A and B and compare and but to the A element which is larger
        while(a>=0 && b>=0){
            if(A[a]>B[b])   A[i--]=A[a--];
            else            A[i--]=B[b--];
        }

        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while(b>=0)         A[i--]=B[b--];
    }
};
*/
int main()
{
    int A[10] = {1, 3, 10, 13};
    int B[5] = {2, 3, 5, 7, 15};
    Solution s;
    s.mergeSortedArray(A, 4, B ,5);
    cout << "Hello world!" << endl;
    return 0;
}
