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
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return build(num, 0, num.size());
    }
    TreeNode *build(vector<int> &num, int start, int end)
    {
        if (start >= end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = build(num, start, mid);
        node->right = build(num, mid + 1, end);
        return node;
    }
};