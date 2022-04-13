#include <bits/stdc++.h>
#define ll long long

ll solveAtMostB(const vector<int> &A, int B) {
    if (B == 0)
        return 0;
    
    unordered_map<int, int> window;
    int j = 0;
    ll res = 0;

    for (int i = 0; i < A.size(); i++) {
        int curr = A[i];
        
        if (window.find(curr) == window.end()) {
            while (window.size() >= B) {
                int pre = A[j];
                window[pre]--;
                if (window[pre] == 0)
                    window.erase(pre);
                j++;
            }
            
            window[curr] = 0;
        }
        
        window[curr]++;
        int addedSubArraysCount = i - j + 1;
        res += ((ll) addedSubArraysCount);
    }

    return res;
}

int Solution::solve(vector<int> &A, int B) {
    ll res = solveAtMostB(A, B) - solveAtMostB(A, B - 1);
    return (int) res;
}