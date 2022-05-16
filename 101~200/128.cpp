{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        int len = 0;
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);
        for (int &i : nums)
        {
            if (st.find(i) == st.end()) continue;
            int prev = i - 1;
            while (st.find(prev) != st.end()) st.erase(prev--);
            int nxt = i + 1;
            while (st.find(nxt) != st.end()) st.erase(nxt++);
            len = max(len, nxt - prev - 1);
        }
        return len;
    }
};