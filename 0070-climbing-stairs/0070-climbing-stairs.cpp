class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 2) {
            return n;
        }
        
        int first = 1;  // Ways to reach the 1st step
        int second = 2; // Ways to reach the 2nd step
        
        // Compute the values up to the n-th step
        for (int i = 3; i <= n; ++i) {
            int current = first + second;
            first = second;
            second = current;
        }
        
        return second;
    }
};
