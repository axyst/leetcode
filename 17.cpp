class Solution {
public:
    vector<string> letterCombinations(string digits) {
        try {
            vector<vector<string>> vec = {{""},{""},{"a", "b", "c"},{"d", "e", "f"},{"g","h","i"},{"j","k","l"},
                                          {"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
            int length = static_cast<int>(digits.size());
            vector<string> ret;
            if (digits.empty()) return ret;
            ret.emplace_back("");
            for (int i = 0; i < length; ++i) {
                vector<string> tmp;
                for (const auto &j : vec[digits[i] - '0']) {
                    for (const auto &each : ret) {
                        tmp.emplace_back(each + j);
                    }
                }
                ret = tmp;
            }
            return ret;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};