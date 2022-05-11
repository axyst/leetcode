class Solution {
public:
    int row = 0;
    int col = 0;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    bool valid(int i, int j)
    {
        return (i>=0&&i<row&&j>=0&&j<col);
    }
    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visiting, string now, string goal) {
        if(now==goal) return true;
        // 加速:重写匹配函数(从头逐个检查即可)
        if(goal.find(now)==string::npos) return false;
        visiting[i][j]=true;
        for(int d=0;d<4;d++)
        {
            int ni=i+dir[d][0];
            int nj=j+dir[d][1];
            if(!valid(ni, nj)) continue;
            if(visiting[ni][nj]) continue;

            if(dfs(ni,nj,board,visiting,now+board[ni][nj],goal))
                return true;
        }
        visiting[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {           
                vector<vector<bool>> visiting(row,vector<bool>(col));
                string str;
                str += board[i][j];
                if(dfs(i,j,board,visiting,str,word)) return true;
            }
        }
        return false;
    }
};