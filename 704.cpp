class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) right = mid;
            else if (target > nums[mid]) left = mid + 1;
            else return mid;
        }
        if (left == right) return nums[left] == target ? left : -1;
        return -1;
    }
};
