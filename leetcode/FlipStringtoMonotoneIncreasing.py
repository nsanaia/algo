class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        zeros = (n + 1) * [0]
        zerosCount = 0
        
        for i, ch in enumerate(s):
            if ch == '0':
                zerosCount += 1
            
            zeros[i + 1] = zerosCount
        
        res = n - zerosCount
        
        for i in range(n):
            beforeOnes = i - zeros[i]
            afterZeros = zerosCount - zeros[i]
            print(str(i) + " " + str(beforeOnes) + " " + str(afterZeros))
            res = min(res, beforeOnes + afterZeros)
        
        return res