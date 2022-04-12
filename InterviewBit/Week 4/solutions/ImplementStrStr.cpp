vector<int> buildKMP(const string & s);
int find(const string& A, const string& B, const vector<int>& KMP);

int Solution::strStr(const string A, const string B) {
    if (B == "" || A == "")
        return -1;
    
    auto KMP = buildKMP(B);
    return find(A, B, KMP);
}

int find(const string& A, const string& B, const vector<int>& KMP) {
    int j = 0;

    for (int i = 0; i < A.length(); i++) {
        while (j > 0 && A[i] != B[j])
            j = KMP[j - 1];
        
        if (A[i] == B[j])
            j++;

        if (j == B.size())
            return i - j + 1;
    }

    return -1;
}


vector<int> buildKMP(const string & s) {
    int N = s.length();
    vector<int> res(N, 0);

    for (int i = 1; i < N; i++) {
        int j = res[i - 1];

        while (j > 0 && s[j] != s[i]) 
            j = res[j - 1];

        if (s[j] == s[i])
            j++;
        
        res[i] = j;
    }

    return res;
}