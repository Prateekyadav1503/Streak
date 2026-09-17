class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // best[i] stores the minimum length of a subarray with sum == target in arr[0..i]
        vector<int> best(n, INT_MAX);
        int sum = 0;
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink the window from the left if the sum exceeds the target
            while (sum > target) {
                sum -= arr[left++];
            }
            
            // If we found a valid subarray sum equal to target
            if (sum == target) {
                int curr_len = right - left + 1;
                // Check if there is a valid non-overlapping subarray to the left
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + curr_len);
                }
                // Update the minimum length ending at or before 'right'
                best[right] = min(curr_len, right > 0 ? best[right - 1] : INT_MAX);
            } else {
                // Carry forward the previous best length if no target sum ends here
                best[right] = right > 0 ? best[right - 1] : INT_MAX;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};