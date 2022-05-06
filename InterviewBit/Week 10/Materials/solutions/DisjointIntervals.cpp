#include <bits/stdc++.h>

void swapLeftRight(vector<vector<int> > &A) {
	for (auto& curr : A) {
		int tmp = curr[0];
		curr[0] = curr[1];
		curr[1] = tmp;
	}
}

int Solution::solve(vector<vector<int> > &A) {
	int res = 0;
	swapLeftRight(A);
	sort(A.begin(), A.end());
	
	int lastRight = INT_MIN;

	for (auto& curr : A) {
		int currRight = curr[0];
		int currLeft = curr[1];
		
		
		if (currLeft > lastRight) {
			res++;
			lastRight = currRight;
		}		
	}	
	
	return res;
}
