class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int sz = chars.size();
        auto beg = chars.begin();
        for (int i = 0; i < sz - 1; i++)
        {
            char &c = chars[i];
            int tmp = i, cnt = 1;
            if (tmp + 1 <= sz - 1)
                while (chars[tmp] == chars[tmp + 1])
                {
                    tmp++;
                    cnt++;
                    if (tmp + 1 > sz - 1) break;
                }
            if (i < tmp)
            {
                if (tmp + 1 > chars.size())
                {
                    cnt -= (tmp + 1 - chars.size());
                    tmp = chars.size() - 1;
                }
                if (cnt <= 1) continue;
                chars.erase(beg + i + 1, beg + tmp + 1);
                string tc = to_string(cnt);
                int inttc = 0;
                for (char ccc : tc)
                {
                    chars.insert(beg + i + 1 + inttc, ccc);
                    inttc++;
                }
                i += inttc;
            }
            if (i >= chars.size() - 1) break;
        }
        return chars.size();
    }
};
