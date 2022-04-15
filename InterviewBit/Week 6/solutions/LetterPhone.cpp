#include <bits/stdc++.h>

static const unordered_map<char, string> NUMBERS_MAPPINGS {
        {'0',"0"},
        {'1',"1"},
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
};

vector<string> Solution::letterCombinations(string A) {
    vector<string> res;
    queue<pair<string, int>> words;
    words.push(make_pair("", 0));

    while (!words.empty()) {
        auto currPair = words.front();words.pop();
        string curr = currPair.first;
        int idx = currPair.second;

        if (idx == A.size()) {
            res.push_back(curr);
            continue;
        }

        for (char ch : NUMBERS_MAPPINGS.at(A[idx])) {
            words.push(make_pair(curr + ch, idx + 1));
        }
    }

    return res;
}




//******************************************* SECOND BETER ***************


void letterCombinationsHelper(string& A, vector<char>& curr, int idx, const unordered_map<char, string>& MAPPER, vector<string>& res);

vector<string> Solution::letterCombinations(string A) {
    unordered_map<char, string> MAPPER {
        {'0',"0"},
        {'1',"1"},
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };

    vector<string> res;
    vector<char> curr(A.size(), '0');

    letterCombinationsHelper(A, curr, 0, MAPPER, res);

    return res;
}

void letterCombinationsHelper(string& A, vector<char>& curr, int idx, const unordered_map<char, string>& MAPPER, vector<string>& res) {
    if (idx == A.size()) {
        res.push_back(string(curr.begin(), curr.end()));
        return;
    }

    for (char ch : MAPPER.at(A[idx])) {
        curr[idx] = ch;
        letterCombinationsHelper(A, curr, idx + 1, MAPPER, res);
    }
}

