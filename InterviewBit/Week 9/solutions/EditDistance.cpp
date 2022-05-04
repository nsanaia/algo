int Solution::minDistance(string A, string B) {
	int dpH = A.size() + 1;
	int dpW = B.size() + 1;
	
	vector<vector<int>> dp(dpH, vector<int>(dpW, 0));
	
	for (int i = 1; i < dpH; i++)
		dp[i][0] = dp[i - 1][0] + 1;
	
	for (int i = 1; i < dpW; i++)
		dp[0][i] = dp[0][i - 1] + 1;
	
	
	for (int r = 1; r < dpH; r++) {
		for (int c = 1; c < dpW; c++) {
			if (B[c - 1] == A[r - 1]) {
				dp[r][c] = dp[r - 1][c - 1];
				continue;
			}
			
			int replace = dp[r - 1][c - 1] + 1;
			int remove = dp[r - 1][c] + 1;
			int add = dp[r][c - 1] + 1;
			dp[r][c] = min(replace, min(add, remove));
		}
	}
	
	
	return dp[A.size()][B.size()]; 
}


