class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0, right = 0;
        int sz = nums.size() - 1;
        while (right <= sz)
        {
            if (nums[left] == 0 && nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++; right++;
            }
            else if (nums[left] == 0) right++;
            else
            {
                if (left < right) left++;
                else right++;
            }
        }
    }
};