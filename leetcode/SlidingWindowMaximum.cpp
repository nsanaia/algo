class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> greaters;       
        
        for (int i = 0; i < nums.size(); i++) {
        
            if (i >= k && nums[i - k] == greaters.front()) {
                greaters.pop_front();   
            }
            
            while (!greaters.empty() && nums[i] > greaters.back()) {
                greaters.pop_back();
            }
            
            greaters.push_back(nums[i]);
            
            if (i >= (k - 1))
                res.push_back(greaters.front());
        }
        
        return res;
    }
};

