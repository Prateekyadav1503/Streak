#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum - x;
        
        // If target < 0, it's impossible to reach x
        if (target < 0) return -1;
        
        // If target == 0, we must remove all elements
        if (target == 0) return nums.size();
        
        int currentSum = 0;
        int maxLen = -1;
        int left = 0;
        
        // Sliding window to find the max length subarray with sum == target
        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];
            
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            if (currentSum == target) {
                maxLen = std::max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
}; 