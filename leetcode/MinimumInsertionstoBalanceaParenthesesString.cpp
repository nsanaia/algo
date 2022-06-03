class Solution {
public:
    int minInsertions(string s) {
        int res = 0;

        int bal = 0;
        int idx = 0;

        while (idx < s.length()) {
            if (s[idx] == '(') {
                bal++;
                idx++;

            } else {
                if (bal > 0) {
                    bal--;
                } else {
                    res++;
                }

                bool isNextRight = (idx + 1) < s.length() && s[idx + 1] == ')';
                idx += isNextRight ? 2 : 1;
                res += isNextRight ? 0 : 1;	
            }
        }

        return res + 2 * bal;	
    }
};