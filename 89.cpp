// 最高位保留，其它位是当前位和它的高一位进行异或操作
class Solution {
public:
	vector<int> grayCode(int n)
	{
		vector<int> ret;
		for (int i = 0; i < (1 << n); i++)
			ret.emplace_back(i ^ (i >> 1));
		return ret;
	}
};