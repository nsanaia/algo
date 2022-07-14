import java.lang.*;

class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int res = 0;
        int posCurrSum = 0;
        int negCurrSum = 0;
        
        for (int num : nums) {
            posCurrSum = num + posCurrSum > 0 ? num + posCurrSum : 0;
            negCurrSum = num + negCurrSum < 0 ? num + negCurrSum : 0;
            
            res = Math.max(res, Math.max(posCurrSum, Math.abs(negCurrSum)));       
        }
        
        return res;
    }
}