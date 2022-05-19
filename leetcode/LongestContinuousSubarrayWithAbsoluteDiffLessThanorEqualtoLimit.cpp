class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {      
        int left = 0;
        int res = 1;
        deque<int> smallers{0};
        deque<int> greaters{0};
        
        for (int i = 1; i < nums.size(); i++) {
            int curr =  nums[i];
            
            while (!greaters.empty() && nums[greaters.back()] < curr) {
                greaters.pop_back();
            }
            greaters.push_back(i);
            
            while (!smallers.empty() && nums[smallers.back()] > curr) {
                smallers.pop_back();
            }
            smallers.push_back(i);
            
            
            while ((nums[greaters.front()] - nums[smallers.front()]) > limit) {
                if (greaters.front() == left)
                    greaters.pop_front();
                if (smallers.front() == left)
                    smallers.pop_front();
                
                left++;
            }
            
            res = max(res, i - left + 1);
        }
        
        return res;
    }
};