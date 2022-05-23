class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int> pq;
        int res = 0;

        for (auto num : sticks) {
            pq.push(-num);
        }
        
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            
            int curr = a + b;
            res += (-curr);
            
            
            pq.push(curr);
        }        
        return res;
    }
};