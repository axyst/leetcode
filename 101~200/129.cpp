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
    int sum_helper(int cur_sum, TreeNode *root)
    {
        if (root == nullptr) return 0;
        cur_sum = cur_sum * 10 + root->val;
        if (!root->left && !root->right) return cur_sum;
        return sum_helper(cur_sum, root->left) + sum_helper(cur_sum, root->right);
    }
    int sumNumbers(TreeNode *root)
    {
        return sum_helper(0, root);
    }
};