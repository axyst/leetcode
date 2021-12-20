class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ret;
        int rborder = 0;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (rborder < left || ret.size() < 1)
                ret.emplace_back(intervals[i]);
            else
                ret[ret.size() - 1][1] = max(rborder, right);
            rborder = max(rborder, right);
        }
        return ret;
    }
};