int Solution::solve(vector<vector<int> > &A) {
	if (A.empty())
		return 0;
		
	int H = A.size();
	int W = A[0].size();
	
	if (W == 0)
		return 0;
	
	vector<vector<int> > dp(H, vector<int>(W, -1));
    dp[H - 1][W - 1] = 1;
	
	for (int r = H - 1; r >= 0; r--) {
		for (int c = W - 1; c >= 0; c--) {
            if (r + 1 < H && A[r + 1][c] > A[r][c] && dp[r + 1][c] != -1) {
                dp[r][c] = dp[r + 1][c] + 1;
            }
            if (c + 1 < W && A[r][c + 1] > A[r][c] && dp[r][c + 1] != -1) {
                dp[r][c] = max(dp[r][c], dp[r][c + 1] + 1);
            }
		}
	}
	
	return dp[0][0];
}
