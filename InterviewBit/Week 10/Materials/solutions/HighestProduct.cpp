#include <bits/stdc++.h>

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int right = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
    int left = A[0] * A[1] * A[A.size() - 1];

    return max(left, right);
}
 