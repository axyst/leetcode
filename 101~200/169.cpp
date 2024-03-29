class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, num = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num) cnt++;
            else if (--cnt < 0)
            {
                num = nums[i];
                cnt = 1;
            }
        }
        return num;
    }
};