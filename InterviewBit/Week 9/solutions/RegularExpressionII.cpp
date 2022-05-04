
struct RegItem{
    int type;
    char ch;
};

vector<RegItem> getRegItems(const string& B) {
    vector<RegItem> res;

    for (int i = B.length() - 1; i >= 0; ) {
        if (B[i] == '.') {
            res.push_back(RegItem{0, '.'});
            i--;
        } else if (B[i] == '*') {
            res.push_back(RegItem{1, B[i - 1]});
            i -= 2;
        } else {
            res.push_back(RegItem{2, B[i]});
            i--;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int Solution::isMatch(const string A, const string B) {
    auto regItems = getRegItems(B);

    int H = A.length() + 1;
    int W = regItems.size() + 1;

    vector<vector<bool>> dp(H, vector<bool>(W, false));
    dp[0][0] = true;

    for (int r = 1; r < H; r++) {
        for (int c = 1; c < W; c++) {
            bool charsEqual = regItems[c - 1].ch == '.' || A[r - 1] == regItems[c - 1].ch;
            if (regItems[c - 1].type == 0) {
                dp[r][c] = dp[r - 1][c - 1];

            } else if (regItems[c - 1].type == 1) {
                dp[r][c] = dp[r][c - 1]  
                || (dp[r - 1][c - 1] && charsEqual)
                || (dp[r - 1][c] && charsEqual);

            } else { // case 2 casual char
                dp[r][c] = dp[r - 1][c - 1] && charsEqual;
            }
        }
    }

    return dp[H - 1][W - 1];
}
