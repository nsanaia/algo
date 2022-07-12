class Solution {
    public int maxProfit(int[] prices) {
        int N = prices.length;
        
        if (N <= 1) return 0;
        
        int i = 0;
        int res = 0;
        
        while (i < (N - 1))  {
            int localMin = prices[i];
            
            while ((i + 1) < N && prices[i] <= prices[i + 1]) {
                i++;
            }
            
            int localMax = prices[i];
            res += localMax - localMin;
            
            while ((i + 1) < N && prices[i] >= prices[i + 1]) {
                i++;
            }       
        }
        
        return res;
    }
}