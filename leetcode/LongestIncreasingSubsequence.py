class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not len(nums):
            return 0
        
        dp = [nums[0]]
        
        for i in range(1, len(nums)):
            num = nums[i]
            
            if num > dp[-1]:
                dp.append(num)
            else:
                dp[self.find_first_greater_elem_idx(dp, num)] = num
            
        
        return len(dp)
    
    def find_first_greater_elem_idx(self, dp: List[int], num):
        left = 0
        right = len(dp) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            if num == dp[mid]:
                return mid
            elif num > dp[mid]:
                left = mid + 1
            else: # num < dp[mid]
                right = mid
            
        
        return left