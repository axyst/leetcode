class Solution
{
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int isz, jsz;
    vector<vector<int>> visp, visa, ret;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        isz = heights.size(), jsz = heights[0].size();
        visp = visa = vector<vector<int>>(isz, vector<int>(jsz, 0));
        for (int i = 0; i < isz; i++)
        {
            dfs(heights, visp, i, 0);       // left
            dfs(heights, visa, i, jsz - 1); // right
        }
        for (int j = 0; j < jsz; j++)
        {
            dfs(heights, visp, 0, j);       // up
            dfs(heights, visa, isz - 1, j); // down
        }
        return ret;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j)
    {
        if (vis[i][j]) return;
        vis[i][j] = 1;
        if (visp[i][j] && visa[i][j]) ret.push_back({i, j});
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if (ni < 0 || ni >= isz || nj < 0 || nj >= jsz) continue;
            if (grid[ni][nj] < grid[i][j]) continue;
            dfs(grid, vis, ni, nj);
        }
    }
};