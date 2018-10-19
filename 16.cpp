class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        try {
            int mn = INT32_MAX;
            int res = 0;
            sort(nums.begin(), nums.end());
            int len = static_cast<int>(nums.size());
            for (int k = 0; k < len; ++k) {
                int i = k + 1, j = len - 1;
                while (i < j) {
                    if (abs(nums[i] + nums[j] + nums[k] - target) < abs(mn)) {
                        mn = abs(nums[i] + nums[j] + nums[k] - target);
                        res = nums[i] + nums[j] + nums[k];
                    }
                    if (nums[i] + nums[j] + nums[k] < target) ++i;
                    else --j;
                }
            }
            return res;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};