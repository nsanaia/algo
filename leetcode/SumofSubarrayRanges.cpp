class Solution {
public:
    
    vector<pair<int, int>> getIntervals(vector<int>& nums, bool maxes) {
        int N = nums.size();
        vector<pair<int, int>> dp(N + 1);
        
        stack<int> monotonicStack;
        nums.push_back(maxes ? INT_MAX : INT_MIN);
        
        for (int i = 0; i < N + 1; i++) {
            
            while (!monotonicStack.empty() 
                   && (
                       (maxes && nums[monotonicStack.top()] < nums[i])
                       || (!maxes && nums[monotonicStack.top()] > nums[i])
                        )) {
                       
                dp[monotonicStack.top()].second = i - 1;
                monotonicStack.pop();
            }
            
            dp[i].first = monotonicStack.empty() ? 0 : monotonicStack.top() + 1;
            monotonicStack.push(i);
        }
        
        nums.pop_back();
        
        return dp;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        auto maxes = getIntervals(nums, true);
        auto mines = getIntervals(nums, false);
        
        long long res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            long long count = ((maxes[i].second - i + 1) * (i - maxes[i].first + 1))
                        - ((mines[i].second - i + 1) *  (i - mines[i].first + 1));
            
            res += count * nums[i];
        }
        
        return res;   
    }
};