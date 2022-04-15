// note better space complexityn is possible

int Solution::trap(const vector<int> &A) {
    int N = A.size();
    vector<int> leftMaxes(N, 0);

    int lastMax = INT_MIN;
    for (int i = 0; i < N; i++) {
        leftMaxes[i] = max(lastMax, A[i]);
        lastMax = leftMaxes[i];
    }

    int res = 0;
    lastMax = INT_MIN;
    for (int i = N - 1; i >= 0; i--) {
        lastMax = max(lastMax, A[i]);
        res += (min(lastMax, leftMaxes[i]) - A[i]);
    }

    return res;
}
