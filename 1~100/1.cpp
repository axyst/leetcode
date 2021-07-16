class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mp;
        vector<int> ret;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            int ot = target - nums[i];
            if (mp.count(ot))
            {
                ret.emplace_back(i);
                ret.emplace_back(mp[ot]);
                return ret;
            }
            mp[nums[i]] = i;
        }
        return ret;
    }
};