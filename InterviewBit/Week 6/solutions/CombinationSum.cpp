void fillCombinations(vector<int> &A, int B, vector<int>& curr, int idx, vector<vector<int> >& res) {
    if (B < 0)
        return;

    if (B == 0) {
        res.push_back(curr);
        return; 
    }

    for (int i = idx; i < A.size(); i++) {
        if (i > 0 && A[i] == A[i - 1])
            continue;

        int num = A[i];
        curr.push_back(num);
        fillCombinations(A, B - num, curr, i, res);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > res;
    vector<int> curr;

    sort(A.begin(), A.end());
    fillCombinations(A, B, curr, 0, res);

    return res;
}
