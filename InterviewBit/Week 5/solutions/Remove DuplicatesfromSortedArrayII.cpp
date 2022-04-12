void removeExtraElems(vector<int> &A, int startIdx);

int Solution::removeDuplicates(vector<int> &A) {
    int N = A.size();
    int j = 0;

    for (int i = 0; i < N; i++) {
        if (j > 1 && A[i] == A[j - 1] && A[i] == A[j - 2])
            continue;
        
        A[j] = A[i];
        j++;
    }

    removeExtraElems(A, j);
    return A.size();
}

void removeExtraElems(vector<int> &A, int startIdx) {
    for (int i = A.size() - 1; i >= startIdx; i--) {
        A.pop_back();
    }
}