#define ll long long


int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    ll sum = -1;
    ll diff = LLONG_MAX;

    for (int i = 0; i < A.size(); i++) {
        int l = i + 1;
        int r = A.size() - 1;

        while (r > l) {
            ll currSum = A[i] + A[l] + A[r];
            
            if (currSum == B) {
                return B;
            }

            if (currSum < B)l++;
            else r--;
            
            if (abs(B - currSum) < diff) {
                sum = currSum;
                diff = abs(B - sum);
            }
        }
    }

    return (int) sum;
}
