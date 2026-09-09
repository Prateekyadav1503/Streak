class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = n; // Initialize with a value larger than any possible distance
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        
        return ans;
    }
};