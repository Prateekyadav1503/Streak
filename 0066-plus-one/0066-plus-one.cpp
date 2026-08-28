class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        // Iterate from the least significant digit (rightmost) to the most significant (leftmost)
        for (int i = digits.size() - 1; i >= 0; --i) {
            // Case 1: The current digit is less than 9
            if (digits[i] < 9) {
                digits[i]++; // Simply increment the digit
                return digits; // No more carry, return early
            }
            
            // Case 2: The current digit is 9
            digits[i] = 0; // It becomes 0, and carry propagates to the left
        }
        
        // Case 3: All digits were 9 (e.g., 999 becomes 000)
        // We need to prepend a 1 at the beginning to make it 1000
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};