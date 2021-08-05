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
    void dfs(vector<vector<int>> &ret, vector<int> cur, int targetSum, int sum, TreeNode *node)
    {
        if (node == nullptr) return;
        cur.emplace_back(node->val);
        int newsum = sum + node->val;
        if (targetSum == newsum && node->left == nullptr && node->right == nullptr)
        {
            ret.emplace_back(cur);
            return;
        }
        dfs(ret, cur, targetSum, newsum, node->left);
        dfs(ret, cur, targetSum, newsum, node->right);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr) return {};
        int val = root->val;
        vector<vector<int>> ret;
        vector<int> curr;
        dfs(ret, curr, targetSum, 0, root);
        return ret;
    }
};