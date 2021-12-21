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
    map<int, int> ord;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int sz = inorder.size();
        for (int i = 0; i < sz; i++) ord[inorder[i]] = i;
        TreeNode *root = build(preorder, inorder, 0, sz - 1, 0);
        return root;
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preleft, int preright, int inleft)
    {// current root: pre: preleft, in: rt
        if (preleft > preright) return nullptr;
        int rt = ord[preorder[preleft]];
        TreeNode *root = new TreeNode(preorder[preleft]);
        int lsz = rt - inleft;
        root->left = build(preorder, inorder, preleft + 1, preleft + lsz, inleft);
        root->right = build(preorder, inorder, preleft + lsz + 1, preright, rt + 1);
        return root;
    }
};