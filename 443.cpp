class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int end = 0, l = 0, r = 0;
        while (r < chars.size())
        {
            l = r;
            while (r < chars.size() && chars[l] == chars[r]) r++;
            chars[end++] = chars[l];
            if (r - l == 1) continue;
            for (const auto &x : to_string(r - l))
                chars[end++] = x;
        }
        return end;
    }
};
