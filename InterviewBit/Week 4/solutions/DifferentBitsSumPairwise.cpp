#define ll long long
#define MOD 1000000007L

ll onesCountAtIdx(const vector<int> &A, int idx) {
    int mask = 1 << idx;
    ll res = 0;

    for (int i = 0; i < A.size(); i++) {
        if (mask & A[i])
            res++;
    }

    return res;
}

int Solution::cntBits(vector<int> &A) {
    ll res = 0;
    ll N = (ll) A.size(); 

    for (int i = 0; i <= 31; i++) {
        ll onesCount = onesCountAtIdx(A, i);
        ll zerosCount = N - onesCount;
        ll curr =(onesCount * zerosCount) % MOD;
        curr = (curr * 2) % MOD;
        res = (res + curr) % MOD;
    }

    return (int) res;
}