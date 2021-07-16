class Solution
{
public:
    string intToRoman(int num)
    {
        string ret;
        int nb[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string ch[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        for (int i = 12; i >= 0; --i)
        {
            while (num / nb[i] > 0)
            {
                ret += ch[i];
                num -= nb[i];
            }
        }
        return ret;
    }
};