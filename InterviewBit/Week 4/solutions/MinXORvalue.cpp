#include <bits/stdc++.h>

int Solution::findMinXor(vector<int> &A) {
    int res = INT_MAX;
    sort(A.begin(), A.end());

    for (int i = 1; i < A.size(); i++) {
        int curr = A[i - 1] ^ A[i];
        res = min(curr, res);
    }

    return res;
}