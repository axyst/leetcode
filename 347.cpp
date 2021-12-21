
typedef pair<int, int> pii;
class Solution
{
public:
    static bool cmp(pii &a, pii &b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> cnt;
        priority_queue<pii, vector<pii>, decltype(&cmp)> q(cmp);
        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        for (auto &[num, count] : cnt)
        {
            if (q.size() < k) q.push(make_pair(num, count));
            else if (q.top().second < count)
            {
                q.pop();
                q.push(make_pair(num, count));
            }
        }
        vector<int> ret;
        while (!q.empty())
        {
            ret.push_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};