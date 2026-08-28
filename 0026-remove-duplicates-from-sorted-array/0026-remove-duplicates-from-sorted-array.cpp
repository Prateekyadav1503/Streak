class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Handle edge case for empty array
        if (nums.empty()) {
            return 0;
        }
        
        // 'insertIndex' keeps track of the position to place the next unique element
        int insertIndex = 1; 
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous one, it's unique
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i]; // Move unique element to the front
                insertIndex++;               // Increment the count/index
            }
        }
        
        // The total number of unique elements
        return insertIndex;
    }
};