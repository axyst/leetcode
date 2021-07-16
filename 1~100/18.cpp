// 枚举双指针两端
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        set<vector<int>> vs;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if (sz < 4) return {};
        for (int k = 0; k < sz; ++k)
        {
            for (int l = k + 1; l < sz; ++l)
            {
                int sub = target - nums[k] - nums[l];
                int i = l + 1, j = sz - 1;
                while (i < j)
                {
                    if (nums[i] + nums[j] == sub)
                    {
                        vs.insert({nums[k], nums[l], nums[i], nums[j]});
                        while (i < j && nums[i] == nums[i + 1])
                            ++i;
                        while (i < j && nums[j] == nums[j - 1])
                            --j;
                        ++i, --j;
                    }
                    else if (nums[i] + nums[j] < sub)
                        ++i;
                    else --j;
                }
            }
        }
        ret = vector<vector<int>>(vs.begin(), vs.end());
        return ret;
    }
};