// from solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        try {
            vector<string> ret;
            if (!n) ret.emplace_back("");
            else
                for (int i = 0; i < n; ++i) {
                    for (const auto &left: generateParenthesis(i))
                        for (const auto &right: generateParenthesis(n - 1 - i)) {
                            string cur;cur += ("(");cur += left;cur += ")";cur += right;
                            ret.emplace_back(cur);
                        }
                }
            return ret;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    };
};