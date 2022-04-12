
vector<int> generateIndexes(int startIdx, int count) {
    vector<int> res;

    for (int i = startIdx; i < (startIdx + count); i++)
        res.push_back(i);

    return res;
}

int countBetween(int start, int end) {
    return end - start + 1;
}


// Time O(N) | Space O(1)
vector<int> Solution::maxone(vector<int> &A, int B) {
    pair<int, int> res{0, 0};
    int left = 0;
    int zerosCount = 0;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 0)
            zerosCount++;

        while (zerosCount > B && left <= i) {
            if (A[left] == 0)
                zerosCount--;
            left++;
        }

        int currRes = countBetween(left, i);
        if (currRes > res.second)
            res = {left, currRes};
    
    }

    return generateIndexes(res.first, res.second);
}