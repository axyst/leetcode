
class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int sum = 0, smax = 20005;
        int l = S.length();
        for (int i = 0; i < l; i++)
            if (S[i] != '1') sum++;
        smax = sum;
        for (int i = 0; i < l; i++)
        {
            if (S[i] == '0') sum--;
            else sum++;
            if (sum < smax) smax = sum;
        }
        return smax;
    }
};
