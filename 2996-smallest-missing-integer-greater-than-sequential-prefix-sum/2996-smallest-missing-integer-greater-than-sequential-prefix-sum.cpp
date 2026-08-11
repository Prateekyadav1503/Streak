
class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        // Step 1: Calculate the sum of the longest sequential prefix
        int prefix_sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            // A prefix is sequential if each element is exactly 1 greater than the previous
            if (nums[i] == nums[i - 1] + 1) {
                prefix_sum += nums[i];
            } else {
                break; // Break as soon as the sequence is interrupted
            }
        }
        
        // Step 2: Store all array elements in a hash set for O(1) lookups
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        
        // Step 3: Find the smallest missing integer >= prefix_sum
        while (num_set.count(prefix_sum)) {
            prefix_sum++;
        }
        
        return prefix_sum;
    }
};