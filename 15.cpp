// 双指针
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        if (!nums.empty() && nums.back() < 0)
            return {};
        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.emplace_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1])
                        ++i;
                    while (i < j && nums[j] == nums[j - 1])
                        --j;
                    ++i, --j;
                }
                else if (nums[i] + nums[j] < target)
                    ++i;
                else
                    --j;
            }
        }
        return ret;
    }
};