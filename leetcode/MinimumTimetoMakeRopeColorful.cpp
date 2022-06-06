#include <bits/stdc++.h>

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int N = colors.size();
 
        int idx = 0;
        
        while (idx < N) {
        	char ch = colors[idx];

            int consecutiveSums = neededTime[idx];
            int consecutivesMax = neededTime[idx];

            while ((idx + 1) < N && colors[idx + 1] == ch) {
                idx++;
                
                consecutiveSums += neededTime[idx];
                consecutivesMax = max(consecutivesMax, neededTime[idx]);
            }
            

            res -= consecutivesMax;
            res += consecutiveSums;   
            idx++;
        }    
        
        return res;
    }
};