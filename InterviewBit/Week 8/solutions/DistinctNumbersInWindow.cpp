#include <bits/stdc++.h>


vector<int> Solution::dNums(vector<int> &A, int B) {
	unordered_map<int, int> numCountMap;
	vector<int> res;
	
	for (int i = 0; i < A.size(); i++) {
		int num = A[i];
		numCountMap[num]++;
		
		if (i == (B - 1)) {
			res.push_back(numCountMap.size());

		} else if (i > (B - 1)) {
			int numToRemove = A[i - B];
			numCountMap[numToRemove]--;
			if (numCountMap[numToRemove] == 0)
				numCountMap.erase(numToRemove);
		
			res.push_back(numCountMap.size());
		}
	}
	
	return res;
}

