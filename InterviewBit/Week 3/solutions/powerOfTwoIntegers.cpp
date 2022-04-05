#include <bits/stdc++.h>

int Solution::isPower(int A) {
    for (int a = 2; (a * a) <= A; a++) {
        int p = log(A) / log(a);
        if (p > 1 && pow(a, p) == A)
            return 1;
    }

    return A == 1;
}