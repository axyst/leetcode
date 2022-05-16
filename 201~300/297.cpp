// vector TLE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ret = "";
        serial(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream stream(data);
        list<string> str;
        string seg;
        while (getline(stream, seg, ','))
        {
            str.push_back(seg);
        }
        return deserial(str);
    }
    TreeNode *deserial(list<string> &str)
    {
        if (str.size() == 0) return nullptr;
        if (str.front() == "None")
        {
            str.erase(str.begin());
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(str.front()));
        str.erase(str.begin());
        root->left = deserial(str);
        root->right = deserial(str);
        return root;
    }
    void serial(TreeNode *root, string &data)
    {
        if (root == nullptr)
        {
            data += "None,";
            return;
        }
        data += to_string(root->val);
        data += ",";
        serial(root->left, data);
        serial(root->right, data);
        return;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));