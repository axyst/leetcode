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
    bool sum_helper(TreeNode *root, int targetSum, int cur)
    {
        if (root == nullptr) return false;
        if (root->val + cur == targetSum && root->left == nullptr && root->right == nullptr) return true;
        return (sum_helper(root->left, targetSum, root->val + cur) || sum_helper(root->right, targetSum, root->val + cur));
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return sum_helper(root, targetSum, 0);
    }
};