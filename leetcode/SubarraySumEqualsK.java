import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
        int res = 0;
        
        Map<Long, Integer> prefixSums = new HashMap<>();
        prefixSums.put(0L, 1);
        
        long lastPrefix = 0;
        
        for (int num : nums) {
            long currPrefix = lastPrefix + num;
            
            if (prefixSums.containsKey(currPrefix - k)) res += prefixSums.get(currPrefix - k);
            
            prefixSums.put(currPrefix, prefixSums.getOrDefault(currPrefix, 0) + 1);
            lastPrefix = currPrefix;
        }
        
        return res;
    }
}