class Solution
{
public:
    int mySqrt(int x)
    {
        long left = 0, right = x, mid = left;
        while (left < right)
        {
            mid = left + ((right - left) / 2);
            if (mid * mid < x)
                left = mid + 1;
            else
                right = mid;
        }
        if (left * left > x)
            return (int)left - 1;
        return (int)left;
    }
};