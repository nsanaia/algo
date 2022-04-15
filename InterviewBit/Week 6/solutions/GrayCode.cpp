#include <bits/stdc++.h>


vector<int> Solution::grayCode(int A) {
    vector<int> res{0, 1};

    for (int i = 1; i < A; i++) {
        int len  = res.size();
        for (int j = len - 1; j >= 0; j--) {
            res.push_back(res[j] + (1 << (i)));
        }
    }

    return res;
}



//****************************************** Second way **************************************************************

int getOpposite(int a) {
    return a == 0 ? 1 : 0;
}

void grayCodeHelper(vector<int>& curr, vector<vector<int>>& res, int A) {
    if (curr.size() == A) {
        res.push_back(curr);
        return;
    }

    // left still same
    curr.push_back(res.empty() ?  0 : res[res.size() - 1][curr.size()]);
    grayCodeHelper(curr, res, A);
    curr.pop_back();

    // right change
    curr.push_back(getOpposite(res[res.size() - 1][curr.size()]));
    grayCodeHelper(curr, res, A);
    curr.pop_back();
}

int fromBinary(const vector<int> & binary) {
    int res = 0;

    for (int i = binary.size() - 1; i >= 0; i--) {
        if (binary[i] == 1)
            res += (1 << (binary.size() - 1 - i));
    }

    return res;
}

vector<int> fromBinaries(const vector<vector<int>>& binaries) {
    vector<int> res;

    for (auto& binary : binaries)
        res.push_back(fromBinary(binary));

    return res;
}

vector<int> Solution::grayCode(int A) {
    if (A == 0)
        return {};

    vector<vector<int>> res;
    vector<int> curr;
    grayCodeHelper(curr, res, A);

    return fromBinaries(res);
}



