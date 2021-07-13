class Solution
{
public:
	int minSetSize(vector<int> &arr)
	{
		unordered_map<int, int> mp;
		for (int i : arr)
			++mp[i];
		vector<int> vec;
		for (auto &i : mp)
			vec.push_back(i.second);
		sort(vec.begin(), vec.end(), greater<int>());
		int ret = 0, cnt = 0;
		for (int i : vec)
		{
			++ret;
			cnt += i;
			if (cnt * 2 >= arr.size())
				break;
		}
		return ret;
	}
};