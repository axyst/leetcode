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
    int mx = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        maxPath(root);
        return mx;
    }
    int maxPath(TreeNode *root)
    {
        if (root == nullptr) return 0;
        int left = max(maxPath(root->left), 0);
        int right = max(maxPath(root->right), 0);
        mx = max(mx, left + right + root->val);
        return max(left, right) + root->val;
    }
};