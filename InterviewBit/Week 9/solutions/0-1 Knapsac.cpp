
int solveHelper(int c, int w, vector<int> &V, vector<int> &W,vector<vector<int>>& cache) {
	if (c == 0 || w < 0)
		return 0;
	
	if (cache[w][c] != -1)
		return cache[w][c];
	
	int res = solveHelper(c, w - 1, V, W, cache);
	
	if ((c - W[w]) >= 0)
		res =  max(res, V[w] + solveHelper(c - W[w], w - 1, V, W, cache));	
	
 	
 	cache[w][c] = res;
 	return res;	  
}


int Solution::solve(vector<int> &A, vector<int> &B, int C) {
	vector<vector<int>> cache(B.size(), vector<int>(C + 1, -1));
	
    return solveHelper(C, B.size() - 1, A, B, cache);
}





// *********************************** secon solution ****************************************************/

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
	vector<vector<int>> cache(B.size() + 1, vector<int>(C + 1, 0));

    for (int w = 0; w <= B.size(); w++) {
        for (int c = 0; c <= C; c++) {
            if (c == 0 || w == 0)
                continue;

            int currRes = cache[w - 1][c];
            if ((c - B[w - 1]) >= 0)
                currRes = max(currRes, cache[w - 1][c - B[w - 1]] + A[w - 1]);
            
            cache[w][c] = currRes;
        }
    }
	
    return cache[B.size()][C];
}





// *********************************** 3rd best solution ****************************************************/

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> cache(C + 1, 0);

    for (int w = 0; w <= B.size(); w++) 
        for (int c = C; c >= B[w - 1]; c--)
            cache[c] = max(cache[c], cache[c - B[w - 1]] + A[w - 1]);
	
    return cache[C];
}



