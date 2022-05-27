class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, int> lastIndexes;
        unordered_map<char, int> lastAdditions;
        
        
        int res = 0;
        int pre = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            int lastIdx = lastIndexes.find(ch) == lastIndexes.end() ? -1 : lastIndexes[ch];
            int lastAddition = lastAdditions.find(ch) == lastAdditions.end() ? 0 : lastAdditions[ch];
            
            int curr = i - lastIdx;
            curr -= lastAddition;
            curr += pre;
            
            res += curr;
            pre = curr;
            
            lastIndexes[ch] = i;
            lastAdditions[ch] = i - lastIdx;
        }
        
        
        return res;
    }
};