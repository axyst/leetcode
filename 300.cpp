/* n^2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[2505];
        int ret=0;  
        for(int i=0;i<n;++i)  
        {  
            dp[i]=1;
            for(int j=0;j<i;++j)  
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i], dp[j]+1);  
            ret=max(dp[i],ret);  
        }
        return ret;
    }
};
*/
// nlogn
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(int i=0;i<nums.size();i++)
        {
            if(lis.empty() || lis.back() < nums[i]) // add to longest lis
                lis.push_back(nums[i]);
            else // nums[i] is now end of new lis
            {
                auto mn = lower_bound(lis.begin(), lis.end(), nums[i]);
                *mn = nums[i];
            }
        }
        return lis.size();
    }
};