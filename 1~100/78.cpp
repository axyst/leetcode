class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ret;
        int maxl = nums.size();
        for (int i = 0; i < (1 << maxl); i++)
        {
            vector<int> cur;
            for (int j = 0; j < maxl; j++)
            {
                if (i & (1 << j))
                    cur.push_back(nums[j]);
            }
            ret.push_back(cur);
        }
        return ret;
    }
};