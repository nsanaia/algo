#include <bits/stdc++.h>

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
	vector<pair<int, int>> days;
	int N = arrive.size();
	
	for (int i = 0; i < N; i++) {
		days.push_back({depart[i], 0});
		days.push_back({arrive[i], 1});
	}
	
	sort(days.begin(), days.end());
	
	int currBookingsNum = 0;
	for (auto& p : days) {
		int isArrive = p.second == 1;
		
		if (isArrive) {
			currBookingsNum++;
			if (currBookingsNum > K)
				return false;	
		
		} else {
			currBookingsNum--;
		}
	}
	
	return true;
}
