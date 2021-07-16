class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT32_MIN && abs(divisor) == 1)
            return divisor < 0 ? INT32_MAX : INT32_MIN;
        else if (dividend == INT32_MAX && abs(divisor) == 1)
            return divisor < 0 ? INT32_MIN : INT32_MAX;
        if (divisor == INT32_MIN)
            return dividend == INT32_MIN;
        int ret = 0;
        int sym = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        if (divisor < 0) divisor = -divisor;
        if (dividend == INT32_MIN)
        {
            ret++;
            dividend += divisor;
        }
        if (dividend < 0) dividend = -dividend;
        while (dividend >= divisor)
        {
            int a = divisor;
            int m = 1;
            while ((a << 1) > 0 && (a << 1) < dividend)
            {
                a <<= 1;
                m <<= 1;
            }
            ret += m;
            dividend -= a;
        }
        return (!sym) ? ret : -ret;
    }
};