#include <bits/stdc++.h>

#define MOD 10000003L
#define ll long long


ll getSum(vector<int> &C);
ll binarySearch(int A, vector<int> &C);
pair<bool, ll> isPossible(int A, vector<int> &C, ll maxLimit);

int Solution::paint(int A, int B, vector<int> &C) {
    return (int) ((binarySearch(A, C) * B) % MOD);
}

ll binarySearch(int A, vector<int> &C) {
    ll left = 1;
    ll right = getSum(C);
    ll res = LLONG_MAX;
    while (left <= right) {
        ll mid = (left + right) / 2;
        auto currRes= isPossible(A, C, mid);

        if (currRes.first) {
            res = currRes.second;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }

    return res % MOD;
}



ll getSum(vector<int> &C) {
    ll res = 0;
    for (auto c : C)
        res += c;
    return res;
}


pair<bool, ll> isPossible(int A, vector<int> &C, ll maxLimit) {
    ll currSum = 0;
    ll maxSum = LLONG_MIN;
    for (auto c : C) {
        if ((currSum + c) > maxLimit) {
            A--;
            if (A <= 0)
                return {false, -1};
            currSum = c;
        } else {
            currSum += c;   
        }

        maxSum = max(maxSum, currSum);
    }

    return {true, maxSum};
} 