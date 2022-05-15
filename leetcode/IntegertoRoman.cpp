class Solution {
    
public:
    
    string getRomanForOneDigit(int digit,
                            string one,
                            string four,
                            string five,
                            string nine) {
        if (digit == 9) {
            return nine;
        } else if (digit == 4) {
            return four;
        }
        
        string res = digit >= 5 ? five : "";
        
        for (int i = 1; i <= (digit % 5); i++)
            res += one; 
        
        return res;
    }
    
    string intToRoman(int num) {
        if (num == 0)
            return "";
        
        string res = "";
        
        if (num >= 1000) {
            int thousandsCount = num / 1000;
            while (thousandsCount--) 
                res += 'M';
            
            return res + intToRoman(num % 1000);
            
        } else if (num >= 100){
            return getRomanForOneDigit(num / 100, "C", "CD", "D", "CM") + intToRoman(num % 100);
            
        } else if (num >= 10) {
            return getRomanForOneDigit(num / 10, "X", "XL", "L", "XC") + intToRoman(num % 10);
        }
        
        return getRomanForOneDigit(num, "I", "IV", "V", "IX");
    }
};