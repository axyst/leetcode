// DP 数据大时上矩阵乘法
class Solution {
public:
	int countVowelPermutation(int n)
	{
		long long a = 1, e = 1, i = 1, o = 1, u = 1, ret = 0;
		const long long MOD = 1e9 + 7;
		for (int j = 1; j < n; j++)
		{
			long long a_, e_, i_, o_, u_;
			a_ = (e + i + u) % MOD;
			e_ = (a + i) % MOD;
			i_ = (e + o) % MOD;
			o_ = i;
			u_ = (i + o) % MOD;
			a = a_, e = e_, i = i_, o = o_, u = u_;
		}
		ret = (a + e + i + o + u) % MOD;
		return ret;
	}
};