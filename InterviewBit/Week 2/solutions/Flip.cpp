#include <bits/stdc++.h>

struct Info {
    int left;
    int right;
    int diff;
};

vector<int> Solution::flip(string A) {
    Info res{0, 0, 0};
    Info curr{0, 0, 0};
    bool found = false;

    for (int i = 0; i < A.length(); i++) {
        char ch = A[i];
        if (ch == '0') {
            if (!found) 
                curr = {i, i, 0};

            curr.diff++;
            curr.right = i;
            found = true;              

            if (curr.diff > res.diff)
                res = curr;

        } else if (found) {
            
            if (curr.diff == 0)
                found = false;
            else 
                curr.diff--;
        }
    }

    if (res.diff > 0)
        return {res.left + 1, res.right + 1};
    
    return {};
}