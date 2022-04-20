#include <bits/stdc++.h> 

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	int count;
};

class Trie {
	private:
		TrieNode* root;
	public:
		Trie(vector<string> &words) {
			root = new TrieNode();
			for (auto& word : words)
				addWord(word);
		}
		
		void addWord(string& word) {
			TrieNode* curr = root;
			
			for (char ch : word) {
				auto& children = curr -> children;
				
				if (children.find(ch) == children.end()) {
					children[ch] = new TrieNode();
					children[ch] -> count = 0;
				}
				
				curr = children[ch];
				curr -> count++;
			}
		}
		
		string getUniquePrefix(string& word) {
			TrieNode* curr = root;
			
			for (int i = 0;  i < word.size(); i++) {
				char ch = word[i];
				curr = curr -> children[ch];

				if (curr -> count == 1)
					return word.substr(0, i + 1);
			}
			
			return word;
		}
};

vector<string> Solution::prefix(vector<string> &A) {
	Trie trie(A);
	vector<string> res;
	for (auto& word : A)
		res.push_back(trie.getUniquePrefix(word));
	
	return res;
}