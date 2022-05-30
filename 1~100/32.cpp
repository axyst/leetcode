class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int len = 0, left = 0, right = 0;
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == "(") left++;
            else right++;
            if (left == right) len = max(len, left + right);
            else if (right > left) left = right = len = 0;
        }
        left = right = 0;
        for (int i = strlen(s) - 1; i >= 0; i--)
        {
            if (s[i] == "(") left++;
            else right++;
            if (left == right) len = max(len, left + right);
            else if (left > right) left = right = len = 0;
        }
        return len;
    }
};