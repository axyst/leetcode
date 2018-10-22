class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &candidates, int target, int id) {
        if (target == 0) res.emplace_back(path);
        if (target <= 0) return;
        int sz = static_cast<int>(candidates.size());
        for (int i = id + 1; i < sz; ++i) {
            int cur = candidates[i];
            path.emplace_back(cur);
            dfs(candidates, target - cur, i);
            while (i < sz && candidates[i] == candidates[i + 1]) ++i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        try {
            sort(candidates.begin(), candidates.end());
            int sz = static_cast<int>(candidates.size());
            for (int i = 0; i < sz; ++i) {
                int cur = candidates[i];
                path.emplace_back(cur);
                dfs(candidates, target - cur, i);
                while (i < sz && candidates[i] == candidates[i + 1]) ++i;
                path.pop_back();
            }
            return res;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};
