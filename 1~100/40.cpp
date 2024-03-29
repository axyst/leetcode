class Solution
{
public:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

    void dfs(int pos, int rest)
    {
        if (rest == 0)
        {
            ans.emplace_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first)
            return;
        dfs(pos + 1, rest);
        // 当前pos最多使用次数
        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i)
        {// 塞入i个当前值
            sequence.emplace_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i)
            sequence.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        for (int num : candidates)
        {
            if (freq.empty() || num != freq.back().first) 
                freq.emplace_back(num, 1);
            else ++freq.back().second;
        }
        dfs(0, target);
        return ans;
    }
};
