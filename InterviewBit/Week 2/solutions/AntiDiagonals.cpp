vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    if (A.empty())
        return {};

    int N = A.size();
    vector<vector<int> > res(N - 1 + N);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int idx = r + c;
            res[idx].push_back(A[r][c]);
        }
    }

    return res;
}
