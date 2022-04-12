#include <bits/stdc++.h>

pair<int, int> getIntIndexes(const string& A);
int atoiInternal(const string& A, int startIdx, int count, bool isNegative);
bool checkOverflowPositive(int dest, int src);
bool checkOverflowNegative(int dest, int src);


int Solution::atoi(const string A) {
    auto intIndexes = getIntIndexes(A);
    if (intIndexes.second <= 0)
        return 0;

    bool isNegative = intIndexes.first > 0 && A[intIndexes.first - 1] == '-';
    bool containsSign = intIndexes.first > 0 && (A[intIndexes.first - 1] == '-' || A[intIndexes.first - 1] == '+');

    if ((!containsSign && intIndexes.first > 0) || (containsSign && intIndexes.first > 1))
        return 0;

    return atoiInternal(A, intIndexes.first, intIndexes.second, isNegative);
}

bool checkOverflowPositive(int dest, int src) {
    int upperLimit = (INT_MAX - src) / 10;
    return dest > upperLimit;
}

bool checkOverflowNegative(int dest, int src) {
    int lowerLimit = (INT_MIN + src) / 10;
    return dest < lowerLimit;
}


int atoiInternal(const string& A, int startIdx, int count, bool isNegative) {
    int res = 0;
    bool (*overFlowChecker) (int, int) = isNegative ? checkOverflowNegative : checkOverflowPositive;

    for (int i = startIdx; i < (startIdx + count); i++) {
        int num = (A[i] - '0');
        if (overFlowChecker(res, num)) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        res = res * 10;
        if (isNegative)
            num *= -1;

        res += num;
    }

    return res;
}

pair<int, int> getIntIndexes(const string& A) {
    pair<int, int> res{-1, 0};

    for (int i = 0; i < A.length(); i++) {
        if ('0' <= A[i] && A[i] <= '9') {
            if (res.first == -1)
                res.first = i;
            res.second++;

        } else if (res.first != -1){
            return res;
        }
    }

    return res;
}

