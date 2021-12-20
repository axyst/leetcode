class Solution
{
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int isz = 0;
    int jsz = 0;
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        grid[i][j] = '0';
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if (ni < 0 || nj < 0 || ni >= isz || nj >= jsz) continue;
            if (grid[ni][nj] == '0') continue;
            dfs(ni, nj, grid);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ret = 0;
        isz = grid.size();
        jsz = grid[0].size();
        for (int i = 0; i < isz; i++)
        {
            for (int j = 0; j < jsz; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ret++;
                }
            }
        }
        return ret;
    }
};