#include <bits/stdc++.h>
// using namespace std;


unordered_map<string, unordered_set<string>> getOneConnectedWords(vector<string> &C);
bool isOneConnectedWords(const string& a, const string &b);
int getMinDist(const string& start, const string& end, unordered_map<string, unordered_set<string>>& graph);

int Solution::solve(string A, string B, vector<string> &C) {
    if (A == B)
        return 0;

    C.push_back(A);
    C.push_back(B);

    auto oneConnectedWords = getOneConnectedWords(C);

    return  getMinDist(A, B, oneConnectedWords);
}

int getMinDist(const string& start, const string& end, unordered_map<string, unordered_set<string>>& graph) {
    queue<string> nodes;
    nodes.push(start);
    unordered_set<string> visited;
    visited.insert(start);
    int level = 0;


    while (!nodes.empty()) {
        int currLevelLen = nodes.size();
        level++;

        for (int i = 0; i < currLevelLen; i++) {
            auto  curr = nodes.front();
            nodes.pop();

            if (curr == end)
                return level;
            
            for (string next : graph[curr]) {
                if (visited.find(next) != visited.end())
                    continue;
                nodes.push(next);
                visited.insert(curr);
            }
        }
    }

    return -1;
}


unordered_map<string, unordered_set<string>> getOneConnectedWords(vector<string> &C) {
    unordered_map<string, unordered_set<string>> res;

    for (auto& word : C)
        res[word] = {};

    for (int i = 0; i < C.size(); i++) {
        for (int j = i + 1; j < C.size(); j++) {
            string& a = C[i], &b = C[j];
            if (isOneConnectedWords(a, b)) {
                res[a].insert(b);
                res[b].insert(a);
            }
        }
    }

    return res;
}


bool isOneConnectedWords(const string& a, const string &b) {
    int diffCharCount = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            diffCharCount++;
    
        if (diffCharCount > 1)
            return false; 
    }
    return true;
}

