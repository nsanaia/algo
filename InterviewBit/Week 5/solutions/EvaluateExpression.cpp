#include <bits/stdc++.h>


bool isNumeric(const string & s) {
    char lastChar = s[s.length() - 1];
    return lastChar >= '0' && lastChar <= '9';
}

int Solution::evalRPN(vector<string> &A) {
    stack<int> nums;

    for (string s : A) {

        if (isNumeric(s)) {
            nums.push(stoi(s));
            continue;
        }

        int b = nums.top();nums.pop();
        int a = nums.top();nums.pop();
        int currRes;

        if (s == "+") {
            nums.push(a + b);

        } else if (s == "-") {
            nums.push(a - b);

        } else if (s == "*") {
            nums.push(a * b);

        } else if (s == "/") {
            nums.push(a / b);
        }
    }

    return nums.top();
}
