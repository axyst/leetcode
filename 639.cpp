// https://leetcode.com/problems/decode-ways-ii/discuss/105274/python-straightforward-with-explanation
class Solution {
public:
    int numDecodings(string s) {
        longlong MOD = 1e9 + 7;
        long long e0 = 1, e1 = 0, e2 = 0;
        for (char c : s)
        {
            if (c == '*')
            {
                f0 = 9 * e0 + 9 * e1 + 6 * e2;
                f1 = e0;
                f2 = e0;
            }
            else
            {
                f0 = (c > '0') * e0 + e1 + (c <= '6') * e2;
                f1 = (c == '1') * e0;
                f2 = (c == '2') * e0;
            }
            e0 = f0 % M, e1 = f1, e2 = f2;
        }
        return e0;
    }
};