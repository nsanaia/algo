class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        
        int preProd = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = preProd;
            preProd *= nums[i];
        }
        
        preProd = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= preProd;
            preProd *= nums[i];
        }
        
        return ans;
    }
};