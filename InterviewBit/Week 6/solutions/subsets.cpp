#include <bits/stdc++.h>

void subsetsHelper(vector<int> &A, int idx, vector<int>& prefix,vector<vector<int>>& res);

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());

    vector<vector<int>> res{};
    vector<int> prefix;

    subsetsHelper(A, 0, prefix, res);

    return res;
}


void subsetsHelper(vector<int> &A, int idx, vector<int>& prefix,vector<vector<int>>& res) {
    res.push_back(prefix);

    for (int i = idx; i < A.size(); i++) {
        prefix.push_back(A[i]);
        subsetsHelper(A, i + 1, prefix, res);
        prefix.pop_back();
    }
}