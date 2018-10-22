// from solution
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        try {
            int ls = static_cast<int>(nums.size());
            int i = ls - 2;
            while (i >= 0 && nums[i] >= nums[i + 1]) --i;
            if (i < 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
            int j = ls - 1;
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    };
};