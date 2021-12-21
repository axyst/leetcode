// substring template
class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> mp;
        int remain;            // substring valid checker
        int left = 0, right = 0; // window pointers
        int slen;                  // substring length
        // subsstring map
        for (char c : t) mp[c]++;
        // customize
        remain = t.size(), slen = INT_MAX;
        int start = 0;
        while (right < s.size())
        {
            if (/* extend window */ mp[s[right++]]-- > 0)
            {
                remain--;
            }
            while (/* valid window */ remain == 0)
            {
                // update slen here if find minimum
                if (slen > (right - left))
                {
                    slen = right - (start = left);
                }
                if (/* shrink window*/ mp[s[left++]]++ == 0)
                {
                    remain++;
                }
            }
            // update slen here if find maximum
        }
        // customize
        return slen == INT_MAX ? "" : s.substr(start, slen);
    }
};