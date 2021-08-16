class NumArray
{
    int *prefix;
public:
    NumArray(vector<int> &nums)
    {
        int sz = nums.size();
        prefix = new int[sz];
        prefix[0] = nums[0];
        for (int i = 1; i < sz; i++)
            prefix[i] = prefix[i - 1] + nums[i];
    }

    int sumRange(int left, int right)
    {
        return prefix[right] - (!left ? 0 : prefix[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */