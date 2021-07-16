class Solution
{
public:
    int myAtoi(string str)
    {
        if (str.length() < 1) // ""
            return 0;
        auto first = str.find_first_not_of(' ');
        if (first == string::npos) // 空行
            return 0;
        str = str.substr(first, str.length());
        int len = str.length();
        int ret = 0;
        if (str[0] != '-' && str[0] != '+' && (str[0] > '9' || str[0] < '0')) // 前导文字串
            return 0;
        for (int i = 0; i < len; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                int bef = str[i] - '0';
                if (ret > INT32_MAX / 10 || (ret == INT32_MAX / 10 && bef > INT32_MAX % 10))
                    return (str[0] == '-') ? INT32_MIN : INT32_MAX; // 溢出
                ret = ret * 10 + bef;
            }
            else // 后置文字串
            {
                if (i == 0) continue;
                break;
            }
        }
        return str[0] == '-' ? -ret : ret; // 负数
    }
};