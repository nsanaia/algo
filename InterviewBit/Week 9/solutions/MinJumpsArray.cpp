#include <bits/stdc++.h>

int Solution::jump(vector<int> &A) {
    if (A.size() < 2)
    	return 0;
    
    int res = 0;
    int maxIndex = 0;
    int nextMaxIndex = 0;
    
    for (int i = 0; i < (A.size() - 1); i++) {
    	nextMaxIndex = max(nextMaxIndex, i + A[i]);	
        if (i == maxIndex) {
            if (nextMaxIndex <= maxIndex)
                return -1;
            maxIndex = nextMaxIndex;
            nextMaxIndex = nextMaxIndex;
            res++;
        }
    }
    

    return res;
}
