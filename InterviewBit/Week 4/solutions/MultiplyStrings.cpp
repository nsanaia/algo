#include <bits/stdc++.h>

char fromInt(int num) {
    return (char) (num + '0');
}

int toInt(char ch) {
    return ch - '0';
}

void add(vector<char> &dest, const vector<char> &src, int startIdx) {
    int carry = 0;
    for (int i = 0; i < src.size(); i++) {
        int destIdx = i + startIdx;
        if (destIdx < dest.size()) {
            int sum = toInt(src[i]) + toInt(dest[destIdx]) + carry;
            dest[destIdx] = fromInt(sum % 10);
            carry = sum / 10;
        } else {
            if (carry == 0) {
                dest.push_back(src[i]);
            } else {
                int sum = carry + toInt(src[i]);
                dest.push_back(fromInt(sum % 10));
                carry = sum / 10;
            }
        }
    }

    if (carry > 0)
        dest.push_back(fromInt(carry));
}

vector<char> mult(const string &A, int num) {
    vector<char> res;
    int carry = 0;

    for (int i = A.length() - 1; i >= 0; i--) {
        int curr = (num * toInt(A[i])) + carry;
        res.push_back(fromInt(curr % 10));
        carry = curr / 10;
    }
    if (carry > 0)
        res.push_back(fromInt(carry));

    return res;
}


void removeZerosFromEnd(vector<char>& res) {
    for (int i = res.size() - 1; i > 0; i--) {
        if (res[i] == '0') {
            res.pop_back();
        } else {
            break;
        }
    }
}   

string Solution::multiply(string A, string B) {
    vector<char> res;

    for (int i = B.length() - 1; i >= 0; i--) {
        vector<char> currRes = mult(A, toInt(B[i]));
        add(res, currRes, B.length() - 1 - i);
    }

    removeZerosFromEnd(res);
    reverse(res.begin(), res.end());
    return string(res.begin(), res.end());
}
