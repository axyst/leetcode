class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int tot = 1;
        sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v)
             { return u[1] < v[1]; });
        int rborder = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (left >= rborder)
            {
                rborder = right;
                tot++;
            }
        }
        return intervals.size() - tot;
    }
};
