#include <bits/stdc++.h>

int Solution::firstMissingPositive(vector<int> &A) {
    int res = 1;
    int N = A.size();

    for (int i = 0; i < N; i++) {
        if (A[i] <= 0)
            A[i] = INT_MAX;
    }

    for (int i = 0; i < N; i++) {
        int curr = abs(A[i]);
        if (curr <= N) {
            A[curr - 1] *= -1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] > 0)
            return (i + 1);
    }

    return N + 1;
}
