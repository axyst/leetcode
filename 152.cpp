class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int pre = nums[0];
        int pre_m = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int mx = pre, mn = pre_m;
            pre = max(mx * nums[i], max(nums[i], mn * nums[i]));
            pre_m = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(ans, pre);
        }
        return ans;
    }
};