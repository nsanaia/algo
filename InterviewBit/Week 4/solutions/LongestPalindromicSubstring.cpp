pair<int, int> getMaxPalindromFrom(const string& A, int left, int right) {
    pair<int, int> res{0, 0};

    while (left >= 0 && right <= A.length()) {
        if (A[left] != A[right])
            return res;

        res = {left, right - left + 1};
        left--;
        right++;
    }

    return res;
}

string Solution::longestPalindrome(string A) {
    if (A.length() == 0)
        return "";
    
    pair<int, int> res{0, 1};

    for (int i = 1; i < A.length(); i++) {
        auto oddPalindrome = getMaxPalindromFrom(A, i, i);
        auto evenPalindrome = getMaxPalindromFrom(A, i - 1, i);

        if (oddPalindrome.second > res.second)
            res = oddPalindrome;
        
        if (evenPalindrome.second > res.second)
            res = evenPalindrome;
    }

    
    return A.substr(res.first, res.second);
}
