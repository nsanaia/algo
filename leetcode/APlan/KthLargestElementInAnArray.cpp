class Solution {
public:
    
    // O(N) time | O(1) space
    int findKthLargest(vector<int>& nums, int k) {
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;
        k = nums.size() - k;
        
        while (true) {
            int partitionIdx = partition(nums, leftIdx, rightIdx);
            
            if (partitionIdx == k) {
                return nums[partitionIdx];
                
            } else if (partitionIdx < k) {
                leftIdx = partitionIdx + 1;
                
            } else {// partitionIdx > k
                rightIdx = partitionIdx - 1;
            }
        }
        
        //illegal state exception
        return -1;
    }
    
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    int partition(vector<int>& nums, int leftIdx, int rightIdx) {
        int pivotIdx = rightIdx;
        int placeHolderForSmallers = leftIdx;
        
        for (int i = leftIdx; i < pivotIdx; i++) {
            if (nums[i] <= nums[pivotIdx]) {
                swap(nums[i], nums[placeHolderForSmallers]);
                placeHolderForSmallers++;
            }
        }
        
        swap(nums[pivotIdx], nums[placeHolderForSmallers]);
        
        return placeHolderForSmallers;
    }  
    
};