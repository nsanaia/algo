class Solution {
public:
    
    string getWordHash(string& word) {
        vector<int> counts(26, 0);
        
        for (char ch : word) {
            counts[ch - 'a']++;
        }
        
        string res = "";
        
        for (int i = 0; i < 26; i++) {
            int count = counts[i];
            if (count > 0) {
                res += to_string(i);
                res += '-';
                res += to_string(count);
                res += ';';
            }
        }
        
        return res;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> groupIds;
         vector<vector<string>> res;
    
        for (auto& word : strs) {
            string hash = getWordHash(word);
            
            if (groupIds.find(hash) == groupIds.end()) {
                groupIds[hash] = res.size();
                res.push_back(vector<string>{});
            }
            
            res[groupIds[hash]].push_back(word);
        }
        
        
        return res;
    }

    
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> groups;
//          vector<vector<string>> res;
    
//         for (auto& word : strs) {
//             string hash = getWordHash(word);
//             groups[hash].push_back(word);
//         }
        
//         for (auto& p : groups) {
//             res.push_back(p.second);
//         }
        
//         return res;
//     }
};