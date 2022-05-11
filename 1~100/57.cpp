class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ret;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int rborder = 0;
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