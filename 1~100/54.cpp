class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        int dir = 1;
        vector<int> ret;
        while (left <= right && up <= down)
        {
            if (dir == 1) // 最上 左到右
            {
                for (int i = left; i <= right; i++)
                    ret.push_back(matrix[up][i]);
                dir = 2;
                up++;
            }
            else if (dir == 2) // 最右 上到下
            {
                for (int i = up; i <= down; i++)
                    ret.push_back(matrix[i][right]);
                dir = 3;
                right--;
            }
            else if (dir == 3) // 最下 右到左
            {
                for (int i = right; i >= left; i--)
                    ret.push_back(matrix[down][i]);
                dir = 4;
                down--;
            }
            else if (dir == 4) // 最左 下到上
            {
                for (int i = down; i >= up; i--)
                    ret.push_back(matrix[i][left]);
                dir = 1;
                left++;
            }
        }
        return ret;
    }
};