class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 1;
        
        // Helper lambda function to expand around a given center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the length of the palindrome found
            return right - left - 1;
        };
        
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd-length palindromes (e.g., "aba", center is s[i])
            int len1 = expandAroundCenter(i, i);
            
            // Case 2: Even-length palindromes (e.g., "abba", center is between s[i] and s[i+1])
            int len2 = expandAroundCenter(i, i + 1);
            
            int currentMaxLen = std::max(len1, len2);
            
            // Update the global maximum window if a longer palindrome is found
            if (currentMaxLen > maxLength) {
                maxLength = currentMaxLen;
                // Calculate the true starting index of the substring
                start = i - (currentMaxLen - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};
