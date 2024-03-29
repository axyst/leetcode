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
    bool sym_helper(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        if (l->val != r->val) return false;
        return sym_helper(l->left, r->right) && sym_helper(l->right, r->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr) return true;
        return sym_helper(root->left, root->right);
    }
};