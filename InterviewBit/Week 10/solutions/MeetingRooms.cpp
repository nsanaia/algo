#include <bits/stdc++.h>

vector<pair<int, int>> getPoints(vector<vector<int> > &A) {
	vector<pair<int, int>> res;
	
	for (auto& interval : A) {
		res.emplace_back(interval[0], 0);
		res.emplace_back(interval[1], 1);
	}
	
	sort(res.begin(), res.end());
	return res;
}

int Solution::solve(vector<vector<int> > &A) {
	auto points = getPoints(A);
	int res = 0;
	int currMeetings = 0;
	
	for (auto& p : points) {
		bool isStart = p.second == 0;
		
		if (isStart)
			currMeetings++;
		else
			currMeetings--;
		
		res = max(currMeetings, res); 
		
	}
	
	return res;
}