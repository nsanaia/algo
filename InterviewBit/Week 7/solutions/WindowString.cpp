#include <bits/stdc++.h>
unordered_map<char, int> getCharsCount(string& B) {
    unordered_map<char, int> res;
    for (auto ch : B) {
        if (res.find(ch) == res.end())
            res[ch] = 0;

        res[ch]++;
    }
    return res;
}

string Solution::minWindow(string A, string B) {
    auto charsCount = getCharsCount(B);
    int Asize = A.size();
    int Bsize = B.size();
    vector<bool> miss(Asize, false);
    unordered_map<char, queue<int>> currChars;
    int j = 0;
    int currCount = 0;
    pair<int, int> res{0, INT_MAX};

    for (int i = 0; i < Asize; i++) {
        char ch = A[i];
        if (charsCount.find(ch) == charsCount.end())
            continue;

        if (currChars.find(ch) == currChars.end()) {
            queue<int> q;
            currChars[ch] = q;
        }

        currChars[ch].push(i);

        if (currChars[ch].size() <= charsCount[ch]) {
            currCount++;
        } else {
            miss[currChars[ch].front()] = true;
            currChars[ch].pop();
        }

        while (miss[j] || charsCount.find(A[j]) == charsCount.end()) {
            j++;
        }

        if (currCount == Bsize) {
            int currLen = i - j + 1;
            if (currLen < res.second) {
                res = {j, currLen};
            }
        }

    }

    if (res.second == INT_MAX)
        return "";
    return A.substr(res.first, res.second);
}