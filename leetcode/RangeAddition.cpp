class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    	   vector<int> res(length, 0);
    	   
    	   for (auto& update : updates) {
                int start = update[0];
                int end = update[1] + 1;
                int val = update[2];

                res[start] += val;
                if (end < length)
                    res[end] -= val;
    	   }
    	   
    	   
    	   int pre = 0;
    	   for (int i = 0; i < length; i++) {
                res[i] += pre;
                pre = res[i];
    	   }
     	   
    	   return res;
    }
};