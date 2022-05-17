class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int maxDamage = INT_MIN;
        long long sum = 1;
        
        for (auto d : damage) {
            maxDamage = max(maxDamage, d);
            sum += ((long long) d);
        }
        
        sum -= ((long long) (maxDamage >= armor ? armor : maxDamage));
        
        return sum;
    }
};