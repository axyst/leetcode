class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ret;
        if (numRows == 1) return s;
        vector<string> vec(numRows);
        bool down = false;
        int now = 0; // 行
        for (auto i : s)
        {
            vec[now] += i;
            if (now == 0 || now == numRows - 1)
                down = !down;
            down ? ++now : --now;
        }
        for (int i = 0; i < numRows; ++i)
            ret += vec[i];
        return ret;
    }
};