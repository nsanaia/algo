#include <bits/stdc++.h>

// Time O(N * logN) | Space O(N)
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> res;
    multiset<int> window;

    for (int i = 0; i < A.size(); i++) {
        int num = A[i];
        window.insert(num);
        if (window.size() == B) {
            res.push_back((*window.rbegin()));
            window.erase(window.lower_bound(A[i - B + 1]));

        }
    }

    return res;
}


// ********************************************** second way ***************************************

// Time O(N) | Space O(N)
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<pair<int, int>> window;
    vector<int> res;

    for (int i = 0; i < A.size(); i++) {
        int num = A[i];

        while (!window.empty() && window.back().second < num) {
            window.pop_back();
        }

        window.push_back(make_pair(i, num));

        if (i >= (B - 1)) {
            if (window.front().first <= (i - B))
                window.pop_front();
            res.push_back(window.front().second);
        }
    }

    return res;
}
