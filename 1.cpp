class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> mp;
        try {
            vector<int> ret;
            auto size = nums.size();
            for (auto i = 0; i < size; ++i) {
                auto ot = target - nums[i];
                if (mp.count(ot)) {
                    ret.emplace_back(i);
                    ret.emplace_back(mp[ot]);
                    return ret;
                }
                mp[nums[i]] = i;
            }
            throw ("no solution");
        }
        catch (const exception &exc) {
            cerr << exc.what() << endl;
        }
    }
};