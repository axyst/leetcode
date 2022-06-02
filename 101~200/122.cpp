class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int empty = 0;int holding = -prices[0];
        for(int i=1;i<sz;i++)
        {
            int e_old = empty;
            int h_old = holding;
            empty=max(e_old,h_old+prices[i]);
            holding=max(e_old-prices[i],h_old);
        }
        return max(empty,holding);
    }
};