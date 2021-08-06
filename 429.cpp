/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr) return {};
        queue<Node*> q;
        q.emplace(root);
        vector<vector<int> > ret;
        while(!q.empty())
        {
            vector<int>cur;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                Node* f = q.front();
                q.pop();
                cur.emplace_back(f->val);
                for(int j=0;j<f->children.size();j++)
                    q.emplace(f->children[j]);
            }
            ret.emplace_back(cur);
        }
        return ret;
    }
};