class Solution
{
public:
    bool P(int i, int j) { return i > j; }

    bool P2(int i, int j) { return i >= j; }

    int upper(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid = -1;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (P(nums[mid], target)) r = mid;
            else l = mid + 1;
        }
        return l - 1; // 第一个大于的左边
    }

    int lower(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid = -1;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (P2(nums[mid], target)) r = mid;
            else l = mid + 1;
        }
        return r; // 第一个等于
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int low = lower(nums, target);
        int up = upper(nums, target);
        if (low > up) // 没有找到 up多减了1
            return vector<int>{-1, -1};
        return vector<int>{low, up};
    }
};