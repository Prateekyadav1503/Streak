class Solution {
public:
    int mySqrt(int x) {
        // Base cases for 0 and 1
        if (x == 0 || x == 1) {
            return x;
        }
        
        int left = 1;
        int right = x / 2; // The square root of x (where x > 1) is never greater than x / 2
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Using division instead of (mid * mid <= x) to completely prevent integer overflow
            if (mid <= x / mid) {
                ans = mid;       // 'mid' is a potential answer, look for a larger one
                left = mid + 1;
            } else {
                right = mid - 1; // 'mid' is too large, look on the left side
            }
        }
        
        return ans;
    }
};
