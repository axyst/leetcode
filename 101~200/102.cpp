/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> vec;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *fr = q.front();
                q.pop();
                if (fr == nullptr) continue;
                vec.push_back(fr->val);
                q.push(fr->left);
                q.push(fr->right);
            }
            if (vec.size() > 0) ret.push_back(vec);
        }
        return ret;
    }
};