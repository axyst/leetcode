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
    void traverse_helper(TreeNode *root, vector<int> &ret)
    {
        if (root == nullptr) return;
        traverse_helper(root->left, ret);
        ret.push_back(root->val);
        traverse_helper(root->right, ret);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        traverse_helper(root, ret);
        return ret;
    }
};