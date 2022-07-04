class Solution:
    FIRST_TWENTY = [ '', 'One', 'Two', 'Three', 'Four', 'Five',
                    'Six', 'Seven', 'Eight', 'Nine', 'Ten',
                    'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen',
                    'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen', 'Twenty']

    TENS = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']

    NAMES = ['Billion', 'Million', 'Thousand', '']


    def triplet_to_words(self, num: int) -> str:
        if num == 0:
            return None
        
        res = ''
        
        if num >= 100:
            res += self.FIRST_TWENTY[num // 100] + ' Hundred'
            num = num % 100
            
        
        if num > 0:
            if len(res):
                res += ' '
            
            if num <= 20:
                res += self.FIRST_TWENTY[num]
            else:
                print(num)
                res += self.TENS[num // 10]
                num = num % 10
                
                if num > 0:
                    res += ' ' + self.FIRST_TWENTY[num]
        
        return res
    
    
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'
        
        res = ''
        divisor = 1000 * 1000 * 1000
        
        for name in self.NAMES:
            curr_triplet = self.triplet_to_words(num // divisor)
            
            if curr_triplet:
                if len(res):
                    res += ' '
                    
                res += curr_triplet
                
                if divisor > 100:
                    res += ' ' + name
            
            num = num % divisor
            divisor = divisor // 1000
        
        return res