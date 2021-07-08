class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int r = matrix.size(), c = matrix[i].size();
        priority_queue<int> q;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                q.emplace(matrix[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};