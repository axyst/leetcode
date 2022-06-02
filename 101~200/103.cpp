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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        bool dir = true;
        while (!q.empty())
        {
            deque<int> tmp;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (dir) tmp.push_back(cur->val);
                else tmp.push_front(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            dir = !dir;
            ret.push_back(vector<int>{tmp.begin(), tmp.end()});
        }
        return ret;
    }
};