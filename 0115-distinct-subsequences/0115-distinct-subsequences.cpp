#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();
        
        // dp[j] stores the number of distinct subsequences of s 
        // that match the prefix of t of length j.
        std::vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: an empty string t has 1 match
        
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return static_cast<int>(dp[n]);
    }
};
