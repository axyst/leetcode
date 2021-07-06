// 枚举上边界 枚举下边界 枚举左边界 二分单行前缀和找右边界 O(m^2 n logn）
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
	{
        int ret = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) // up
		{ 
            vector<int> line(n);
            for (int j = i; j < m; j++) // down
			{
                for (int l = 0; l < n; l++)
                    line[l] += matrix[j][l];
                set<int> sum{0};
                int cur = 0;
                for (int l : line) // left
				{
                    cur += l;
                    auto lb = sum.lower_bound(cur - k); // right
                    if (lb != sum.end())
                        ret = max(ret, cur - *lb);
                    sum.insert(cur);
                }
            }
        }
        return ret;
    }
};