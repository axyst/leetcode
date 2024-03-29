class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        vector<int> dp(sz);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < sz; i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[sz - 1];
    }
};