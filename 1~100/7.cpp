class Solution
{
public:
    int reverse(int x)
    {
        int ret = 0;
        int multi = 1;
        while (x != 0)
        {
            if (ret > INT32_MAX / 10 || ret < INT32_MIN / 10) return 0;
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};