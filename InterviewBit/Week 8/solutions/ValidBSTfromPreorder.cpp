#include <bits/stdc++.h>

struct Info {
	bool isPos;
	int endIdx;
};

Info solveHelper(vector<int> &A, int idx, int minVal, int maxVal) {
	if (idx == A.size())
		return {true, idx};
		
	int curr = A[idx];
	
	if (curr < minVal)
		return {false, 0};
	
	if (curr > maxVal)
		return {true, idx};
	
	auto leftRes = solveHelper(A, idx + 1, minVal, curr);
	if (!leftRes.isPos)
		return {false, 0};
	
	auto rightRes  = solveHelper(A, leftRes.endIdx, curr, maxVal);
	if (!rightRes.isPos)
		return {false, 0};
	
	return {true, rightRes.endIdx};
}


int Solution::solve(vector<int> &A) {
	auto res = solveHelper(A, 0, INT_MIN, INT_MAX);
	return res.isPos && res.endIdx == A.size();
}




// ************************************* 2nd way ***********************************


#include <bits/stdc++.h>

int Solution::solve(vector<int> &A) {
	int currRoot = INT_MIN;
	stack<int> nums;
	
	for (auto num : A) {
		if (num <= currRoot)
			return false;
		
		while (!nums.empty() && num > nums.top()) {
            currRoot = nums.top();
			nums.pop();
        }
		
		nums.push(num);
	}
	
	return true;
}
