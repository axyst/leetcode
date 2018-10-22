// from discussion
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &candidates, int target, int id) {
        if (target == 0) res.emplace_back(path);
        if (target <= 0) return;
        int sz = static_cast<int>(candidates.size());
        for (int i = id; i < sz; ++i) {
            int cur = candidates[i];
            path.emplace_back(cur);
            dfs(candidates, target - cur, i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        try {
            dfs(candidates, target, 0);
            return res;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};