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
            if (P(nums[mid], target))
                r = mid;
            else
                l = mid + 1;
        }
        return l - 1;
    }

    int lower(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid = -1;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (P2(nums[mid], target))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int low = lower(nums, target);
        int up = upper(nums, target);
        if (low > up)
            return vector<int>{-1, -1};
        return vector<int>{low, up};
    }
};