#include <bits/stdc++.h>

// Time O(N * B * b) | space O(B)

unordered_map<string, int> getWordsMap(const vector<string>& B) {
    unordered_map<string, int> res;
    for (auto& word : B)
            res[word]++;
    return res;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    if (A.empty() || B.empty())
            return {};

    auto wordsMap = getWordsMap(B);
    vector<int> res;

    int bSize = B[0].length();

    for (int i = 0; i < A.size(); i++) {
        unordered_map<string, int> currWords;
        int Bcount = B.size();
        for (int j = 0; j < B.size(); j++) {
            string word = A.substr(i + j * bSize, bSize);

            if (wordsMap.find(word) == wordsMap.end())
                break;
            if (currWords[word] >= wordsMap[word])
                break;

            Bcount--;
            currWords[word]++;
        }
        if (Bcount == 0)
            res.push_back(i);
    }

    return res;
}