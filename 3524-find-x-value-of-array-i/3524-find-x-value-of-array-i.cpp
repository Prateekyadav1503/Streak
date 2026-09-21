

#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            std::vector<long long> new_dp(k, 0);
            int num_mod = num % k;

            // Start a new subarray with only the current element
            new_dp[num_mod]++;

            // Extend all previous subarrays ending at the previous position
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_r = (r * num_mod) % k;
                    new_dp[new_r] += dp[r];
                }
            }

            // Accumulate counts into overall answers
            for (int r = 0; r < k; ++r) {
                ans[r] += new_dp[r];
            }

            dp = std::move(new_dp);
        }

        return ans;
    }
};