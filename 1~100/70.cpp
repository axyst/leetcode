class Solution
{
public:
    int climbStairs(int n)
    {
        int last_2 = 0;
        int last_1 = 0;
        int ret = 0;
        while (n > 0)
        {
            if (last_2 == 0 && last_1 == 0)
                last_1 = 1;
            else
            {
                last_2 = last_1;
                last_1 = ret;
            }
            ret = last_2 + last_1;
            n--;
        }
        return ret;
    }
};