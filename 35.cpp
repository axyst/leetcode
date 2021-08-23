class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else return mid;
        }
        mid = left + (right - left) / 2;
        return nums[mid] >= target ? mid : mid + 1;
    }
};
