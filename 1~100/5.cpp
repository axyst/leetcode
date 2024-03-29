// Manacher
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (!s.length()) return "";
        int len = s.length();
        string str = "$";
        vector<int> vec(len * 2 + 5, 1);
        for (char i : s)
        {
            str += '#';
            str += i;
        }
        str += '#';
        str += '\0';
        int mx = 0, id = 0;
        for (int i = 1; str[i] != '\0'; ++i)
        {
            if (mx > i)
                vec[i] = min(vec[2 * id - i], mx - i);
            while (str[i + vec[i]] == str[i - vec[i]])
                vec[i]++;
            if (i + vec[i] > mx)
            {
                mx = i + vec[i];
                id = i;
            }
        }
        int ans = 1, cen = 0;
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (vec[i] > ans)
            {
                ans = vec[i];
                cen = i;
            }
        }
        int left = cen - ans + 1, right = cen + ans - 1;
        string ret;
        for (int i = left; i < right; ++i)
            if (str[i] != '#')
                ret += str[i];
        return ret;
    }
};