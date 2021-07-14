class Solution {
public:
    string customSortString(string order, string str) {
        map<char,int>mp;
        map<char,int>cnt;
        for(int i=0;i<str.size();i++)
        {
            cnt[str[i]]++;
            int result = order.find(str[i]);
            if(result!=string::npos) mp[str[i]]=result;
        }
        string ret="";
        for(int i=0;i<order.size();i++)
        {
            if(mp.count(order[i])>0&&cnt.count(order[i])>0)
            {
                for(int j=0;j<cnt[order[i]];j++)
                    ret+=order[i];
                cnt[order[i]]=0;
            }
        }
        for(int i=0;i<str.size();i++)
        {
            if(mp.count(str[i])>0&&cnt.count(str[i])>0)
                continue;
            else ret+=str[i];
        }
        return ret;
    }
};