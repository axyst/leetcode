class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> blk[9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                int k = i / 3 * 3 + j / 3;
                int s = board[i][j] - '0' - 1;
                // number s already in row i/col j/block k?
                if (row[s].count(i) == 1) return false;
                else row[s].insert(i);
                if (col[s].count(j) == 1) return false;
                else col[s].insert(j);
                if (blk[s].count(k) == 1) return false;
                else blk[s].insert(k);
            }
        }
        return true;
    }
};