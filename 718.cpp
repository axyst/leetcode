class Solution
{
public:
	int findLength(vector<int> &nums1, vector<int> &nums2)
	{
		int dp[1005][1005];
		int ret = 0;
		int l1 = nums1.size(), l2 = nums2.size();
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				dp[i + 1][j + 1] = (nums1[i] == nums2[j] ? dp[i][j] + 1 : 0);
				ret = max(ret, dp[i + 1][j + 1]);
			}
		}
		return ret;
	}
};