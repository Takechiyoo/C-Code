#include <iostream>

using namespace std;

class Solution
{
public:
    void rotate_L(int nums[], int n, int k)
    {
        if(n == 0) return;
        int temp;
        int index = 0;
        k = k % n;
        while(k>=1)
        {
            temp = nums[n-k];
            for(int i = n-k; i > index; i--)
                nums[i] = nums[i-1];
            nums[index] = temp;
            index++;
            k--;
        }
    }
    void rotate_2(int nums[], int n, int k) {
    for (; k %= n; n -= k)
        for (int i = 0; i < k; i++)
            swap(*nums++, nums[n - k]);
}
};

int main()
{
    int nums[] = {1,2,3,4,5,6,7,8};
    Solution s;
    s.rotate_2(nums, 8, 3);
    for(int i = 0; i < 8; i++)
        cout << nums[i] << ' ';
    cout << endl;
    cout << "Hello world!" << endl;
    return 0;
}

/*
public class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        int tmp = 0, j = 0, cnt = 0;
        k = k % len;
        if(k == 0) return;
        for(int i=0; i<=len; i++) {
            tmp ^= nums[j]; nums[j] ^= tmp; tmp ^= nums[j];
            if(j == cnt && i != 0) {
                j++;
                if(j == k || i == len) {
                    break;
                }
                tmp ^= nums[j]; nums[j] ^= tmp; tmp ^= nums[j];
                cnt++;
            }
            j += k;
            if(j > len-1) {
                j = j- len;
            }
        }
    }
}
*/
