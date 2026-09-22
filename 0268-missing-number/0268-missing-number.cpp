class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Calculate expected sum of numbers from 0 to n
        int expectedSum = n * (n + 1) / 2;
        
        // Calculate the actual sum of numbers in the array
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        
        // The difference is the missing number
        return expectedSum - actualSum;
    }
};
