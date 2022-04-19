#include <bits/stdc++.h>
#define MOD 1000000007L

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> heap;

    for (auto b : B)
        heap.push(b);
    
    long long res = 0;
    for (int i = 0; i < A; i++) {
        int curr = heap.top();
        heap.pop();
        res = (res + (long long)curr) % MOD;
        heap.push(curr / 2);
    }
    return (int) res;
}
