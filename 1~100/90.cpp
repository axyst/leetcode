class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int len = nums.size();
        int N = 1 << len;
        for (int i = 0; i < N; i++)
        {
            vector<int> cur;
            bool skip = false;
            for (int j = 0; j < len; j++)
            {
                if (i & (1 << j))
                {
                    if (j > 0 && !(i & (1 << (j - 1)))) // 同元素没有使用 全部跳过
                        if (nums[j] == nums[j - 1])
                        {
                            skip = true;
                            break;
                        }
                    cur.push_back(nums[j]);
                }
            }
            if (!skip) ret.emplace_back(cur);
        }
        return ret;
    }
};
