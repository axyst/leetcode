class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int sz = nums.size();
        int ret = 0;
        sort(nums.begin(), nums.end());
        for (int i = sz - 1; i >= 2; i--)
        {
            int k = 0, j = i - 1;
            while (k < j)
            {
                int a = nums[i], b = nums[j], c = nums[k];
                if (b + c > a)
                {
                    ret += (j - k);
                    j--;
                }
                else k++;
            }
        }
        return ret;
    }
};