#include <bits/stdc++.h>

bool isPossible(vector<int> &book, int studentsN, int target);

int Solution::books(vector<int> &A, int B) {
    if (B > A.size())
        return -1;

    int sum = 0;
    for (auto num : A) {
        sum += num;
    }

    int low = 0;
    int high = sum;
    int res = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(A, B, mid)) {
            high = mid - 1;
            res = res == -1 ? mid : min(mid, res);

        } else {
            low = mid + 1;
        }
    }

    return res;
}


bool isPossible(vector<int> &books, int studentsN, int target) {
    int currSum = 0;

    for (auto currPage : books) {
        if (currPage > target)
            return false;

        currSum += currPage;

        if (currSum > target) {
            studentsN--;
            if (studentsN == 0)
                return false;

            currSum = currPage;  
        }
    }

    return true;
}