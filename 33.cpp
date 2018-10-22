class Solution {
public:
    int search(vector<int>& nums, int target) {
        try {
            int i;
            int sz = static_cast<int>(nums.size() - 1);
            if (sz < 0) return -1;
            for (i = 0; i < sz; ++i) {
                if (nums[i] > nums[i + 1]) break;
            }
            int left = 0, right = i, mid = 0;
            while (right - left >= 3) {
                mid = left + (right - left) / 2;
                if (nums[mid] == target) return mid;
                if (nums[mid] < target) left = mid;
                else right = mid;
            }
            for (int k = left; k <= right; ++k) {
                if (nums[k] == target) return k;
            }
            left = i + 1, right = sz, mid = 0;
            while (right - left >= 3) {
                if (nums[mid] == target) return mid;
                if (nums[mid] < target) {
                    left = mid;
                } else right = mid;
            }
            for (int k = left; k <= right; ++k)
                if (nums[k] == target) return k;
            return -1;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    };
};
