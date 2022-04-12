#include <bits/stdc++.h>
#define ll long long

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int> > res;
    int N = A.size();
    sort(A.begin(), A.end());

    for (int i = 0; i < (N - 2); i++) {
        if (i > 0 && A[i] == A[i - 1])
            continue;
        
        ll target = 0L - A[i];
        int left = i + 1;
        int right = A.size() - 1;

        while (left < right) {
            ll currSum = (ll)A[left] + (ll)A[right];
            if (currSum < target) {
                left++;
            } else if (currSum > target) {
                right--;
            } else { // == 
                if (left == (i + 1) || A[left - 1] != A[left])
                    res.push_back({A[i], A[left], A[right]});
                left++;
            }
        }
    }

    return res;
}