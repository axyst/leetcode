// CF 1215D
class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.length();
        int ans1 = 0, cnt1 = 0, ans2 = 0, cnt2 = 0;
        int m = n / 2;
        for (int i = 0; i < n; i++)
        {
            if (i < m)
            {
                if (num[i] == '?') cnt1++;
                else ans1 += num[i] - '0';
            }
            else
            {
                if (num[i] == '?') cnt2++;
                else ans2 += num[i] - '0';
            }
        }
        if (cnt1 == cnt2)
        {
            if (ans1 == ans2) return false;
            else return true;
        }
        else if (cnt1 > cnt2)
        {
            if (ans1 >= ans2) return true;
            else
            {
                int ct = cnt1 - cnt2, as = ans2 - ans1;
                if (ct % 2 == 1 || as % 9 != 0 || (as / 9) != ct / 2)
                    return true;
                else return false;
            }
        }
        else
        {
            if (ans2 >= ans1) return true;
            else
            {
                int ct = cnt2 - cnt1, as = ans1 - ans2;
                if (ct % 2 == 1 || as % 9 != 0 || (as / 9) != (ct + 1) / 2)
                    return true;
                else return false;
            }
        }
    }
};