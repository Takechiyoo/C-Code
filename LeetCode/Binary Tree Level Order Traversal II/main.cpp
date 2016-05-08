#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution
{
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector<vector<int> > result;
        queue<TreeNode*> q;
        stack<vector<int> > res_result;
        vector<int> temp;
        if(root == NULL) return result;
        TreeNode *m = new TreeNode(0);
        q.push(root);
        q.push(m);
        TreeNode *t;
        while(true)
        {
            t = q.front();
            q.pop();
            if(t == m)
            {
                res_result.push(temp);
                if(q.empty()) break;
                temp.clear();
                q.push(m);
                continue;
            }
            temp.push_back(t->val);
            if(t->left != NULL)
                q.push(t->left);
            if(t->right != NULL)
                q.push(t->right);
        }
        while(!res_result.empty())
        {
            result.push_back(res_result.top());
            res_result.pop();
        }
        return result;
    }
    vector<vector<int> > res;
/*
void DFS(TreeNode* root, int level)
{
    if (root == NULL) return;
    if (level == res.size()) // The level does not exist in output
    {
        res.push_back(vector<int>()); // Create a new level
    }

    res[level].push_back(root->val); // Add the current value to its level
    DFS(root->left, level+1); // Go to the next level
    DFS(root->right,level+1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    DFS(root, 0);
    return vector<vector<int> > (res.rbegin(), res.rend());
}
*/
};

int main()
{
    TreeNode *root = new TreeNode(1);
    Solution s;
    cout << s.levelOrderBottom(root).size() << endl;
    cout << "Hello world!" << endl;
    return 0;
}
