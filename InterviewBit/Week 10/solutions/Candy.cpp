

int getSum(vector<int> &A) {
	int res = 0;
	
	for (auto num : A)
		res += num;
	
	return res;
}

int Solution::candy(vector<int> &A) {
	int N = A.size();
	vector<int> candies(N, 1);
	
	for (int i = 1; i < N; i++) {
		if (A[i] > A[i - 1])
			candies[i] = candies[i - 1] + 1;
		// else if (A[i] == A[i - 1])
		// 	candies[i] = candies[i - 1];
	}
	
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] > A[i + 1])
			candies[i] = max(candies[i], candies[i + 1] + 1);
		// else if (A[i] == A[i + 1])
		// 	candies[i] = max(candies[i], candies[i + 1]);
	}

	return getSum(candies);
}


// *********************** needs btters space complecity ******************