class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        long long product = 1;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) // prefix
        {
            if (i == 0)
            {
                ret.emplace_back(1);
                continue;
            }
            product *= nums[i - 1];
            ret.emplace_back(product);
        }
        product = 1;
        for (int i = nums.size() - 2; i >= 0; i--) // suffix
        {
            product *= nums[i + 1];
            ret[i] *= product;
        }
        return ret;
    }
};