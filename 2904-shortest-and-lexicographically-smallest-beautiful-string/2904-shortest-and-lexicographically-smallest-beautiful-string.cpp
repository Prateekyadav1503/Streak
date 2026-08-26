class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        int n = s.length();
        int minLength = n + 1;
        int bestLeft = -1;
        int countOnes = 0;
        
        // l = left pointer, r = right pointer
        for (int l = 0, r = 0; r < n; ++r) {
            if (s[r] == '1') {
                countOnes++;
            }
            
            // Shrink the window when we have exactly k '1's
            while (countOnes == k) {
                int currentLength = r - l + 1;
                
                // Case 1: Found a strictly shorter valid substring
                if (currentLength < minLength) {
                    minLength = currentLength;
                    bestLeft = l;
                } 
                // Case 2: Length is a tie; check lexicographical order
                else if (currentLength == minLength) {
                    // s.compare(pos1, len1, s2, pos2, len2) returns < 0 if first is smaller
                    if (s.compare(l, minLength, s, bestLeft, minLength) < 0) {
                        bestLeft = l;
                    }
                }
                
                // Slide the left pointer forward
                if (s[l] == '1') {
                    countOnes--;
                }
                l++;
            }
        }
         // If no valid substring was found, return an empty string
        return (bestLeft == -1) ? "" : s.substr(bestLeft, minLength);
    }
};