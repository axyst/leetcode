class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int sz = nums.size();
        int left = 0, right = sz - 1, mid;
        while (left < right)
        {
            mid = left + (right - left + 1) / 2;
            if (mid - 1 < 0)
                return nums[mid] > nums[mid + 1] ? mid : mid + 1;
            if (mid + 1 > sz - 1)
                return nums[mid] > nums[mid - 1] ? mid : mid - 1;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] >= nums[mid - 1]) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};
