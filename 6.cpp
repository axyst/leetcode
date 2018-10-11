class Solution {
public:
    string convert(string s, int numRows) {
        try {
            string ret;
            auto n = static_cast<unsigned long>(numRows);
            auto len = min(s.length(), n);
            if (len == 1) return s;
            vector<string> vec(len);
            auto down = false;
            auto now = 0;
            for (auto i:s) {
                vec[now] += i;
                if (now == 0 || now == n - 1) down = !down;
                down ? ++now : --now;
            }
            for (auto i = 0; i < len; ++i)
                ret += vec[i];
            return ret;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};