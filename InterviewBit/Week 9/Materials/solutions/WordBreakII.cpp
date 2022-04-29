#include <bits/stdc++.h>

vector<string> wordBreakHelper(string& A, 
                                unordered_set<string>& words,
                                int startIdx,
                                unordered_map<int, vector<string>>& memo) {
	if (memo.find(startIdx) != memo.end())
		return memo[startIdx];
	
	vector<string> res;
	
	for (int i = startIdx; i < A.length(); i++) {
		string curr = A.substr(startIdx, i - startIdx + 1);
		if (words.find(curr) != words.end()) {
			auto currRes = wordBreakHelper(A, words, i + 1, memo);
			for (auto& w : currRes)
				res.push_back(curr + " " + w);

            if (i == (A.length() - 1))
                res.push_back(curr);
		}
	}
	
	memo[startIdx] = res;
	return res;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
	unordered_set<string> words;
	unordered_map<int, vector<string>> memo;
	
	for (auto&  word : B)
		words.insert(word);
	
	auto res =  wordBreakHelper(A, words, 0, memo);
    sort(res.begin(), res.end());
    return res;
}
