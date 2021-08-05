// 双指针
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int len = nums.size();
        for (int i = 0; i < len - 2; i++)
        {
            if (i > 0)
                while (i < len - 2 && nums[i] == nums[i - 1])
                    i++;
            int j = len - 1;
            for (int k = i + 1; k < len - 1; k++)
            {
                if (k > i + 1)
                    while (k < len - 1 && nums[k] == nums[k - 1])
                        k++;
                while (k < j && nums[i] + nums[k] > -nums[j])
                    j--;
                if (k == j) break;
                if (nums[i] + nums[k] == -nums[j])
                    ret.emplace_back({nums[i], nums[k], nums[j]});
            }
        }
        return ret;
    }
};