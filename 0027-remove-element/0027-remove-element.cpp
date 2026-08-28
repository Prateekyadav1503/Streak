class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int writeIndex = 0; // Tracks the position for the next non-val element
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is not the target value
            if (nums[i] != val) {
                nums[writeIndex] = nums[i]; // Move it to the front
                writeIndex++; // Advance the write pointer
            }
        }
        
        return writeIndex; // Total count of elements not equal to val
    }
};