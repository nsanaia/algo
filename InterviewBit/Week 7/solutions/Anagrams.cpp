#include <bits/stdc++.h>

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> wordsMap;

    for (int i = 0; i < A.size(); i++) {
        string word = A[i];

        string wordKey = word;
        sort(wordKey.begin(), wordKey.end());

        if (wordsMap.find(wordKey) == wordsMap.end())
            wordsMap[wordKey] = {};
        
        wordsMap[wordKey].push_back(i + 1);
    }


    vector<vector<int> > res;
    for (auto& p : wordsMap)
        res.push_back(p.second);

    return res;
}