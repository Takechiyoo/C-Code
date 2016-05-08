#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if(root == NULL)    return 0;
        vector<int> deep;
        dfs(root, deep, 1);
        //int minDep = 0;
        int minDep = (*deep.begin());
        for(auto iter = deep.begin(); iter != deep.end(); iter++)
        {
            if((*iter) < minDep)
                minDep = (*iter);
        }
        return minDep;
    }
    void dfs(TreeNode *root, vector<int>& deep, int d)
    {
        if(root == NULL)    return;
        if(root->left == NULL && root->right == NULL)
            deep.push_back(d);
        dfs(root->left, deep, d+1);
        dfs(root->right, deep, d+1);
    }
};

int main()
{
    TreeNode *root = new TreeNode(0);
    Solution s;
    cout << s.minDepth(root) << endl;
    cout << "hello world" << endl;
    return 0;
}
