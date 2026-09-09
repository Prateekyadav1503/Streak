class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long currentThreshold = 1000;
        
        // Loop while the threshold is less than or equal to n.
        // We use check to prevent overflow since constraints say n can be up to 10^15.
        while (currentThreshold <= n) {
            totalCommas += (n - currentThreshold + 1);
            
            // Protect against potential overflow when multiplying by 1000
            if (currentThreshold > LLONG_MAX / 1000) {
                break;
            }
            currentThreshold *= 1000;
        }
        
        return totalCommas;
    }
};
