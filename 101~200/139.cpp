class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        sort(wordDict.begin(), wordDict.end());
        int sz = s.length();
        vector<bool> dp(sz);
        dp[0] = true;
        for (int i = 1; i <= sz; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && binary_search(wordDict.begin(), wordDict.end(), s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sz];
    }
};