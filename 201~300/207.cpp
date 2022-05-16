class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> vis;
    bool dfs(int id)
    {
        vis[id] = 1;
        for (int i = 0; i < graph[id].size(); i++)
        {
            if (!vis[graph[id][i]])
                if (!dfs(graph[id][i]))
                    return false;
            else if (vis[graph[id][i]] == 1)
                return false;
        }
        vis[id] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph.resize(numCourses);
        vis.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
                if (!dfs(i))
                    return false;
        }
        return true;
    }
};