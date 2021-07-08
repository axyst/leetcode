// 滑动窗口
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ret = 0;
        int len = s.length();
        unordered_map<char, int> mp;
        for (int left = 0, right = 0; right < len; ++right)
        {
            if (mp.count(s[right]))
                left = max(mp[s[right]], left);
            ret = max(ret, right - left + 1);
            mp[s[right]] = right + 1;
        }
        return ret;
    }
};