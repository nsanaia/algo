vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > res;
    int height = A.size();

    if (height == 0)
        return {};
    
    int width = A[0].size();

    for (int i = 0; i < (height - 1 + height); i++) {
        res.push_back({});
    }


    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            int idx = r + c;
            res[idx].push_back(A[r][c]);
        }
    }

    return res;
}
