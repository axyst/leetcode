class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
	{
		int m = mat.size(), n = mat[0].size();
		if (m * n != r * c) return mat;
		vector<vector<int>> ret;
		int mm = 0, nn = 0;
		for (int rr = 0; rr < r; rr++)
		{
			vector<int> v;
			for (int cc = 0; cc < c; cc++)
			{
				v.emplace_back(mat[mm][nn]);
				nn++;
				if (nn == n)
				{
					mm++;
					nn = 0;
				}
			}
			ret.emplace_back(v);
		}
		return ret;
	}
};