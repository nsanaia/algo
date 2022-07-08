from functools import cmp_to_key

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        if not len(envelopes):
            return 0
        
        def custom_sort(a, b):
            if a[0] < b[0]:
                return -1

            if a[0] == b[0]:
                return b[1] - a[1]
            
            return 1
            
        envelopes.sort(key=cmp_to_key(custom_sort))
        dp = [envelopes[0][1]]
        
        for i in range(1, len(envelopes)):
            curr = envelopes[i][1]
            
            if curr > dp[-1]:
                dp.append(curr)
            else:
                dp[self.find_first_greater(dp, curr)] = curr
        
        return len(dp)
        
    def find_first_greater(self, dp: List[int], curr: int) -> int:
        left = 0
        right = len(dp) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            if curr == dp[mid]:
                return mid
            elif curr > dp[mid]:
                left = mid + 1
            else: # curr < dp[mid]
                right = mid
        
        return left