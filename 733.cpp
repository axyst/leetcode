class Solution
{
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool vis[55][55];
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int nc)
    {
        if (image[sr][sc] == nc) return image;
        queue<vector<int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;
        int row = image.size();
        int col = image[0].size();
        while (!q.empty())
        {
            vector<int> v = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nsr = v[0] + dir[i][0];
                int nsc = v[1] + dir[i][1];
                if (nsr < 0 || nsr >= row || nsc < 0 || nsc >= col)
                    continue;
                if (vis[nsr][nsc]) continue;
                if (image[nsr][nsc] != image[v[0]][v[1]]) continue;
                q.push({nsr, nsc});
                vis[nsr][nsc] = true;
            }
        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (vis[i][j]) image[i][j] = nc;
        return image;
    }
};