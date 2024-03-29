class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int mn = INT32_MAX;
        int ret = 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int k = 0; k < len; ++k)
        {
            int i = k + 1, j = len - 1;
            while (i < j)
            {
                if (abs(nums[i] + nums[j] + nums[k] - target) < mn)
                {
                    mn = abs(nums[i] + nums[j] + nums[k] - target);
                    ret = nums[i] + nums[j] + nums[k];
                }
                if (nums[i] + nums[j] + nums[k] < target)
                    ++i;
                else
                    --j;
            }
        }
        return ret;
    }
};