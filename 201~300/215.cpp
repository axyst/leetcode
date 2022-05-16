class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1, piv = 0;
        while (true)
        {
            piv = partition(nums, left, right);
            if (piv == k - 1) break;
            if (piv < k - 1) left = piv + 1;
            else right = piv - 1;
        }
        return nums[piv];
    }
    int partition(vector<int> &nums, int left, int right)
    {
        int piv = nums[left];
        int tmp = left;
        while (left < right)
        {
            while (left < right && nums[right] <= piv) right--;
            while (left < right && nums[left] >= piv) left++;
            if (left < right) swap(nums[left], nums[right]);
        }
        swap(nums[tmp], nums[left]);
        return left;
    }
};