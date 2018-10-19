// mine
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        try {
            int len = static_cast<int>(nums.size());
            vector<vector<int>> ret;
            if (len < 3) return ret;
            sort(nums.begin(), nums.end());
            if (nums[0] == 0 && nums[len - 1] == 0) return {{0, 0, 0}};
            set<vector<int>> vset;
            for (int i = 0; i < len; ++i) {
                int left = 0;
                int right = len - 1;
                while (left < right) {
                    if (i == left) ++left;
                    else if (i == right) --right;
                    if (nums[i] + nums[left] + nums[right] > 0 && nums[i] + nums[left] <= 0) --right;
                    else if (nums[i] + nums[left] + nums[right] < 0 && nums[i] + nums[right] >= 0) ++left;
                    else if (nums[i] + nums[left] + nums[right] == 0 && left != right) {
                        vector<int> tmp;
                        tmp.emplace_back(nums[i]);
                        tmp.emplace_back(nums[left]);
                        tmp.emplace_back(nums[right]);
                        sort(tmp.begin(), tmp.end());
                        vset.insert(tmp);
                        ++left;
                    } else break;
                }
            }
            ret = vector<vector<int>>(vset.begin(), vset.end());
            return ret;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};
// shorter solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (!nums.empty() && nums.back() < 0) return {};
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i;
                    --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};