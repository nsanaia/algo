string Solution::longestCommonPrefix(vector<string> &A) {
    if (A.empty())
        return "";
    
    string base = A[0];
    string res = "";

    for (int i = 0;  i < base.length(); i++) {
        char ch = base[i];

        for (string& s : A) {
            if (s[i] != ch)
                return res;
        }
        
        res += ch;
    }

    return res;
}