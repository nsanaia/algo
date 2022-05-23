class Solution {
private:
    static bool cmp(const vector<int> &A, const vector<int> &B) {
        return B[1] < A[1];
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), &cmp);
        
        for (int i = 0; i < boxTypes.size(); i++) {
            int count = boxTypes[i][0];
            int unitN = boxTypes[i][1];
            
            if (count >= truckSize) {
                res += unitN * truckSize;
                break;
                
            } else {
                res += unitN * count;   
                truckSize -= count;
            }
            
        }
        
        return res;
    }
};