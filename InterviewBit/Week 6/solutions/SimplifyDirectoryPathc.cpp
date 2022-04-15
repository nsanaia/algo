#include <bits/stdc++.h>

vector<string> split(const string s) {
    vector<string> tokens;
    istringstream ss(s);
    string token;

    while (getline(ss, token, '/'))
        tokens.push_back(token);

    return tokens;
}

string buildPath(vector<string> tokens, int backNum, bool isFullPath) {
    string res = "/";
    if (!isFullPath) {
        res = "";
        while (backNum > 0) {
            res += "../";
            backNum--;
        }
    }

    int N = tokens.size();

    for (int i = N - 1; i >= 0; i--) {
        string token = tokens[i];
        
        if (i == (tokens.size() - 1))
            res += token;
        else
            res += ("/" + token);
    }

    return res;
}

string Solution::simplifyPath(string A) {
    vector<string> tokens = split(A);
    bool isFullPath = A[0] == '/';
    int backNum = 0;

    vector<string> res;

    for (int i = tokens.size() - 1; i >= 0; i--) {
        string token = tokens[i];

        if (token == "..") {
            backNum++;

        } else if (token != "." && token != "") {
            if (backNum > 0) {
                backNum--;
                continue;
            }
            res.push_back(token);
        }
    }

    return buildPath(res, backNum, isFullPath);
}
