#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Precompute the suffix minimums
        std::vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff_min[i] = std::min(nums[i], suff_min[i + 1]);
        }

        // Step 2: Track prefix maximums and find the smallest stable index
        int pref_max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            pref_max = std::max(pref_max, nums[i]);
            
            // Instability score calculation
            if (pref_max - suff_min[i] <= k) {
                return i; // Return immediately since we want the smallest index
            }
        }

        return -1;
    }
};