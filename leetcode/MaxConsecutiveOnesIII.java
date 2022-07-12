import java.lang.*;

class Solution {
    public int longestOnes(int[] nums, int k) {
        int res = Integer.MIN_VALUE;
        int left = 0;
        
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) {
                k--;
                
                if (k < 0) {
                    while (nums[left] != 0) left++;
                
                    left++;
                    k++;
                }
            }
                
            
            res = Math.max(right - left + 1, res);
        }
        
        return res;
    }
}