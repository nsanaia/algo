int Solution::singleNumber(const vector<int> &A) {
    int res = 0;

    for (auto num : A) {
        res = res ^ num;
    }

    return res;
}