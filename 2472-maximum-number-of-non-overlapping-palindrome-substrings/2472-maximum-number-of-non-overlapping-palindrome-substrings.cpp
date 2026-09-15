#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        int n = s.length();
        // isPal[i][j] stores whether the substring s[i...j] is a palindrome
        std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));

        // Base case: single characters and adjacent identical characters
        for (int i = 0; i < n; ++i) {
            isPal[i][i] = true;
        }

        // Expand around center to find all palindromes
        for (int center = 0; center < n; ++center) {
            // Odd length palindromes
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                isPal[l][r] = true;
                l--;
                r++;
            }
            // Even length palindromes
            l = center;
            r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                isPal[l][r] = true;
                l--;
                r++;
            }
        }

        // dp[i] represents the maximum non-overlapping palindromes in s[0...i-1]
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1]; // carry forward previous maximum
            for (int j = 1; j <= i; ++j) {
                // Check if s[j-1 ... i-1] is a valid palindrome of length at least k
                if (i - (j - 1) >= k && isPal[j - 1][i - 1]) {
                    dp[i] = std::max(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n];
    }
};

