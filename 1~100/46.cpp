class Solution
{
public:
    void get_perm(vector<vector<int>> &ret, vector<int> &cur, int first, int n)
    {
        if (n == first)
        {
            ret.push_back(cur);
            return;
        }
        for (int i = first; i < n; i++)
        {
            swap(cur[i], cur[first]);
            get_perm(ret, cur, first + 1, n);
            swap(cur[i], cur[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;
        get_perm(ret, nums, 0, nums.size());
        return ret;
    }
};