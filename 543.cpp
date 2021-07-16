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
    int mx;
    int dfs(TreeNode *cur)
    {
        if (cur == nullptr) return 0;
        TreeNode *l = cur->left;
        TreeNode *r = cur->right;
        int ld = dfs(l), rd = dfs(r);
        mx = max(mx, ld + rd + 1);
        return max(ld, rd) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        mx = 1;
        dfs(root);
        return mx - 1;
    }
};