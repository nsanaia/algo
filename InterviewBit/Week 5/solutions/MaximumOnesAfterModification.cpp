#include <bits/stdc++.h>

int distBetween(int start, int end) {
    return end - start + 1;
}



// Time O(N) | space - O(B)
// this can be better if do not use deque and use just 2 pointers
int Solution::solve(vector<int> &A, int B) {
    int res = 0;
    int startIdx = 0;
    deque<int> zeroIndexes;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 0) {
            if (zeroIndexes.size() == B) {
                startIdx = zeroIndexes.front() + 1;
                zeroIndexes.pop_front();
            }
            zeroIndexes.push_back(i);
        }

        res = max(res, distBetween(startIdx, i));
    }

    return res;
}