#include <bits/stdc++.h>

int longestValidParenthesesHelper(string& A, bool reverse) {
	int res = INT_MIN;
	int currLen = 0;
	int curr = 0;
	char openCh = reverse ? ')' : '(';

    int i = reverse ? (((int)A.length()) - 1) : 0;
	int step = reverse ? -1 : 1;

	while (i >= 0 && i < A.length()) {
		char ch = A[i];
		if (ch == openCh) {
			curr++;
			currLen++;
		} else {
			curr--;
			if (curr < 0) {
				currLen = 0;
				curr = 0;
			} else {
				currLen++;
			}
		}
		
		if (curr == 0)
			res = max(res, currLen);
        
        i += step;
	}
	
	return res;
}


int Solution::longestValidParentheses(string A) {
	return max(longestValidParenthesesHelper(A, false), longestValidParenthesesHelper(A, true));
}