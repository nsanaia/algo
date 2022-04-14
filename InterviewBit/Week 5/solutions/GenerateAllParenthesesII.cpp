#include <bits/stdc++.h>

vector<string> Solution::generateParenthesis(int A) {
    vector<string> res;
    queue<pair<string, pair<int, int>>> pars;
    pars.push(make_pair("", make_pair(0, 0)));

    while (!pars.empty()) {
        auto currPair = pars.front();pars.pop();
        string curr = currPair.first;
        int opensN = currPair.second.first;
        int closesN = currPair.second.second;

        if (curr.length() == (A * 2)) {
            res.push_back(curr);
            continue;
        } 

        if (opensN < A)
            pars.push(make_pair(curr + "(", make_pair(opensN + 1, closesN)));
            
        if (opensN > closesN)
            pars.push(make_pair(curr + ")", make_pair(opensN, closesN + 1)));
    }

    return res;
}


// ************************************************ second way **************************
#include <bits/stdc++.h>

void generateParenthesisInternal(int A, string s, int openNum, int closeNum, vector<string>& res) {
    if (s.length() == (2 * A)) {
        res.push_back(s);
        return;
    }

    if (openNum < A)
        generateParenthesisInternal(A, s + "(", openNum + 1, closeNum, res);
    
    if (closeNum < openNum)
        generateParenthesisInternal(A, s + ")", openNum, closeNum + 1, res);
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> res;
    generateParenthesisInternal(A, "", 0, 0, res);
    return res;
}
