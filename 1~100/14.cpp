class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int len = strs[0].size();
        string ret = "";
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < strs.size(); j++)
                if (strs[j][i] != strs[0][i]) return ret;
            ret += strs[0][i];
        }
        return ret;
    }
};