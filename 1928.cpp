// Dijkstra加一维时间限制
const int maxn=1005;const int INF=0x3f3f3f3f;
struct Edge
{
    int from,to,dist,tim;
    Edge(int u,int v,int d, int t):from(u),to(v),dist(d),tim(t){}
};
struct HeapNode
{
    int d,u,t;
    HeapNode(int dd,int uu,int tt):d(dd),u(uu),t(tt){}
    bool operator <(const HeapNode &rhs) const
    {
        return d>rhs.d;
    }
};
vector<Edge>edge;vector<int>G[maxn];
bool done[maxn][maxn];int d[maxn][maxn];

void AddEdge(int from,int to,int dist,int tim)
{
    edge.push_back(Edge(from,to,dist,tim));
    G[from].push_back(edge.size()-1);
}
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size(); int m = edges.size();
        for(int i=0;i<n;i++) G[i].clear();
        edge.clear();
        for(int i=0;i<m;i++)
        {
            AddEdge(edges[i][0],edges[i][1],passingFees[edges[i][1]],edges[i][2]);
            AddEdge(edges[i][1],edges[i][0],passingFees[edges[i][0]],edges[i][2]);
        }
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;i++) // 注意时间的区间
            for(int j=0;j<=maxTime;j++)
                {d[i][j]=INF;done[i][j]=0;}
        d[0][0]=passingFees[0];
        Q.push(HeapNode(passingFees[0],0,0));
        while(!Q.empty())
        {
            HeapNode x=Q.top();Q.pop();
            int u=x.u;int t=x.t;
            if(u==n-1) return x.d;
            if(done[u][t]) continue;
            done[u][t]=1;int sz=G[u].size();
            for(int i=0;i<sz;i++)
            {
                Edge&e=edge[G[u][i]];
                if(t+e.tim>maxTime) continue;
                if(d[e.to][t+e.tim]>d[u][t]+e.dist)
                {
                    d[e.to][t+e.tim]=d[u][t]+e.dist;
                    Q.push(HeapNode(d[e.to][t+e.tim],e.to,t+e.tim));
                }
            }
        }
        return -1;
    }
};