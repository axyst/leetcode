// Fisher-Yates
class Solution
{
    vector<int> save;
    vector<int> shuffled;
public:
    Solution(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            save.emplace_back(nums[i]);
            shuffled.emplace_back(nums[i]);
        }
    }

    vector<int> reset()
    {
        return save;
    }

    vector<int> shuffle()
    {
        int n = shuffled.size();
        for (int i = 0; i < n; i++)
        {
            int rd = i + rand() % (n - i);
            swap(shuffled[i], shuffled[rd]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */