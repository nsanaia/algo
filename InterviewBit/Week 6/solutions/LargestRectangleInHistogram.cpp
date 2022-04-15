#include <bits/stdc++.h>

int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> idxes;
    A.push_back(0);
    int res = 0;

    for (int i = 0; i < A.size(); i++) {
        int currHeight = A[i];
        while (!idxes.empty() && A[idxes.top()] > currHeight) {
            int H = A[idxes.top()]; idxes.pop();
            int W = idxes.empty() ? i : i - idxes.top() - 1;
            res = max(res, (H * W));
        }

        idxes.push(i);
    }
    
    return res;
}