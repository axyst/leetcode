// mine (O(2n))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        try {
            auto len = s.length();
            auto ret = 0;
            auto left = 0, right = 0;
            map<char, int> mp;
            while (left < len) {
                while (!mp.count(s[right]) && right < len) {
                    mp[s[right]]++;
                    ++right;
                }
                ret = max(ret, right - left);
                mp.erase(s[left]);
                ++left;
            }
            return ret;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};
// O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        try {
            auto ret = 0;
            auto len = s.length();
            map<char, int> mp;
            for (auto left = 0, right = 0; right < len; ++right) {
                if (mp.count(s[right])) left = max(mp[s[right]], left);
                ret = max(ret, right - left + 1);
                mp[s[right]] = right + 1;
            }
            return ret;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};