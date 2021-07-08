class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int sz = nums.size();
        int i = sz - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i; // 较小数
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = sz - 1;
        while (nums[j] <= nums[i]) --j; // 较大数
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end()); // 重排右边
    }
};