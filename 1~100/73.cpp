class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int mzero[m + 1];
        int nzero[n + 1];
        memset(mzero, 0, sizeof(mzero));
        memset(nzero, 0, sizeof(nzero));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!matrix[i][j])
                    mzero[i] = 1, nzero[j] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mzero[i] || nzero[j])
                    matrix[i][j] = 0;
    }
};