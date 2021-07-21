class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int sz = s.length();
        unordered_map<char,char>mp;
        unordered_map<char,int>used;
        for(int i=0;i<sz;i++)
        {
            if(mp.find(t[i])==mp.end()&&(used.find(s[i])==used.end()))
                {used[s[i]]=1;mp[t[i]]=s[i];continue;}
            else if (mp[t[i]]==s[i]&&used.find(s[i])!=used.end()) 
                continue;
            return false;
        }
        return true;
    }
};