class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least = INT_MAX, profit = 0;
        
        for (auto i: prices) {
            if (i < least)
                least = i;
            profit = max(profit, i - least);
        }
        
        return profit;
    }
};