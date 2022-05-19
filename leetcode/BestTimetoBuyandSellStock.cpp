class Solution {
public:
    int maxProfit(vector<int>& prices) {       
        int res = 0;
        int currMax = prices[prices.size() - 1];
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            res = max(res, currMax - prices[i]);
            currMax = max(currMax, prices[i]);
        }
        
        return res;
    }
};
