class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k equals the size of the array
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }

        // Count global frequencies of all elements
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Case 2: k == 1
        if (k == 1) {
            int max_val = -1;
            for (int num : nums) {
                if (counts[num] == 1) {
                    max_val = std::max(max_val, num);
                }
            }
            return max_val;
        }

        // Case 3: 1 < k < n
        int ans = -1;
        // Check the first element
        if (counts[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        // Check the last element
        if (counts[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }

        return ans;
    }
};