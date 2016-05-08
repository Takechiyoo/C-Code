#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if(root == NULL) return false;
        if(root->left== NULL && root->right == NULL)
        {
            if(root->val == sum)    return true;
            return false;
        }
        vector<int> allPath;
        trasverTree(root, allPath);
        for(vector<int>::iterator it = allPath.begin(); it != allPath.end();)
        {
            if(*it == sum) return true;
            it = allPath.erase(it);
        }
        return false;
    }
    void trasverTree(TreeNode *root, vector<int> &allPath)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
            allPath.push_back(root->val);
        if(root->left != NULL)
        {
            root->left->val += root->val;
           // leftsignal = true;
        }
        if(root->right != NULL)
        {
            root->right-> val += root->val;
            //rightsignal = true;
        }
        trasverTree(root->left, allPath);
        trasverTree(root->right, allPath);
    }
};

int main()
{
    cout << "hello world" << endl;
    return 0;
}
