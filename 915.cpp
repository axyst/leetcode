class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        int ret = 0;
        int mx = nums[0];
        int left = nums[0];
        for (int i = 1; i < n; i++)
        {
            mx = max(mx, nums[i]);
            if (nums[i] < left)
            {
                left = mx;
                ret = i;
            }
        }
        return ret + 1;
    }
};
