class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Edge case: if the input vector is empty, return an empty string
        if (strs.empty()) return "";
        
        // Iterate through each character index of the first string
        for (int i = 0; i < strs[0].length(); ++i) {
            char currentChar = strs[0][i];
            
            // Compare this character with the character at the same index in all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If the current string is shorter than index 'i' OR characters do not match
                if (i == strs[j].length() || strs[j][i] != currentChar) {
                    // Return the valid prefix found up to index i
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // If the loop finishes, the entire first string is the common prefix
        return strs[0];
    }
};