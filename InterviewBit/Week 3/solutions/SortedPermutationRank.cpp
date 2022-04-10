#include <bits/stdc++.h>

#define MOD 1000003
#define ll long long


int Solution::findRank(string A) {
    int N = A.size();
    vector<ll> permutations(N, 0);
    permutations[1] = 1;
    for (int i = 2; i < N; i++) {
        permutations[i] = (permutations[i - 1] * i) % MOD;
    }

    set<char> chars;

    for (char ch : A) {
        chars.insert(ch);
    }

    ll res = 1;
    for (int i = 0; i < N; i++) {
        char ch = A[i];
        int rank = (int) distance(chars.begin(), chars.lower_bound(ch));
        res = (res + (((ll) rank) * permutations[N - 1 - i] % MOD)) % MOD;
        chars.erase(ch);
    }

    return ((int) res);
}