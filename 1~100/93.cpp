class Solution
{
public:
    void ip_helper(vector<string> &ret, vector<string> cur, string s, int first)
    {
        if (cur.size() == 4 && first == s.length())
        {
            string tmp;
            for (int i = 0; i < 4; i++)
            {
                tmp += cur[i];
                if (i < 3) tmp += '.';
            }
            ret.push_back(tmp);
        }
        if (cur.size() == 4 || first == s.length())
            return;
        if (s[first] == '0')
        {
            cur.push_back("0");
            ip_helper(ret, cur, s, first + 1);
            return;
        }
        int num = 0;
        for (int i = first; i < s.length(); i++)
        {
            num = num * 10 + (s[i] - '0');
            if (num < 0 || num > 255) break;
            cur.push_back(to_string(num));
            ip_helper(ret, cur, s, i + 1);
            cur.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ret;
        vector<string> cur;
        ip_helper(ret, cur, s, 0);
        return ret;
    }
};