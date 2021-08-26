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
    unordered_map<int, int> mp;
public:
    bool findTarget(TreeNode *root, int k)
    {
        mp.clear();
        return find(root, k);
    }
    bool find(TreeNode *root, int k)
    {
        if (root == nullptr) return false;
        if (mp[k - root->val] > 0) return true;
        mp[root->val]++;
        return (find(root->left, k) || find(root->right, k));
    }
};
