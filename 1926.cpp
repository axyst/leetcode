// https://ac.nowcoder.com/acm/contest/940/D/ BFS 第一条路
class Solution
{
public:
    typedef pair<int, int> pii;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool vis[105][105];
    int dis[105][105];
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        queue<pii> q;
        int m = maze.size(), n = maze[0].size();
        int ex = entrance[0], ey = entrance[1];
        q.push(make_pair(ex, ey));
        int nums = 0;
        int xx = 0, yy = 0;
        while (!q.empty())
        {
            pii t = q.front();
            q.pop();
            for (int l = 0; l < 4; l++)
            {
                int x = t.first + dx[l];
                int y = t.second + dy[l];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] != '+')
                {
                    vis[x][y] = true;
                    dis[x][y] = dis[t.first][t.second] + 1;
                    if (maze[x][y] == '.' && (x == 0 || x == m - 1 || y == 0 || y == n - 1) && (!(x == ex && y == ey)))
                    {
                        nums++;
                        if (nums == 1)
                        {
                            xx = x;
                            yy = y;
                        }
                        else continue;
                    }
                    else if (maze[x][y] == '.')
                        q.push(make_pair(x, y));
                }
            }
        }
        if (nums == 0) return -1;
        else return dis[xx][yy];
    }
};