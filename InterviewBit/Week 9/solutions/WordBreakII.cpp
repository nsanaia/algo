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


// ************************************ second more complicagted *******************
#include <bits/stdc++.h>

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isEnd;
};

class Trie {
	private:
		TrieNode* root;
	public:
		Trie() {
			root = new TrieNode();
		}
		
		void add(string& word) {
			TrieNode* curr = root;
			
			for (auto ch : word) {
				auto& children = curr -> children;
				if (children.find(ch) == children.end())
					children[ch] = new TrieNode();
				
				curr = children[ch];
			}
			
			curr -> isEnd = true;
		}
		
		TrieNode* getRoot() {
			return root;
		}
		
};

vector<string> wordBreakHelper(string& A, int startIdx, Trie& trie) {
	vector<string> res;
	
	if (startIdx == A.size()) {
		res.push_back("");
		return res;
	}
	
	TrieNode* curr = root;
	
	for (int i = startIdx; i < A.size(); i++) {
		char ch = A[i];
		auto& children = curr -> children;
		if (children.find(ch) == children.end())
			break;
		
		curr = children[ch];
		if (curr -> isEnd) {
			string word = A.susbtr(startIdx, i - startIdx + 1);
			auto currRes = wordBreakHelper(A, i + 1, trie);
			
			for (auto& lastPart : currRes) 
				res.push_back(word + " " + lastPart);
			
		}		
	}
	
	return res;
}


vector<string> Solution::wordBreak(string A, vector<string> &B) {
	Trie trie;
	
	for (auto& word : B)
		trie.add(word);
		
	return wordBreakHelper(A, 0, trie);
	return res;
}
