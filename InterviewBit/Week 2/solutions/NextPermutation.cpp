#include <bits/stdc++.h>

int getMinGreaterElemFromInterval(int target, vector<int> &A, int start, int end) {
    for (int i = end; i >= start; i--)
        if (A[i] > target)
            return i;
    return 0;
}

vector<int> Solution::nextPermutation(vector<int> &A) {

	for (int i = A.size() - 1; i > 0; i--) {
		int curr = A[i];
		int pre = A[i - 1];
		
		if (curr > pre) {
            int minGreaterElemIdx = getMinGreaterElemFromInterval(pre, A, i, A.size() - 1);
			A[i - 1] = A[minGreaterElemIdx];
            A[minGreaterElemIdx] = pre;
			sort(A.begin() + i, A.end());
			return A;
		}
	}
	
	sort(A.begin(), A.end());
	return A;
}