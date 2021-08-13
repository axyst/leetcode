class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        vector<vector<string>> ret;
        int sz = strs.size();
        for (int i = 0; i < sz; i++)
        {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            mp[cur].emplace_back(strs[i]);
        }
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            vector<string> cur;
            for (auto j = (i->second).begin(); j != (i->second).end(); j++)
                cur.emplace_back(*j);
            ret.emplace_back(cur);
        }
        return ret;
    }
};