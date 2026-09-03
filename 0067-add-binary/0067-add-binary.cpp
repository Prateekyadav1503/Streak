#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop as long as there are characters left in either string, or a carry remains
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // Append the remainder bit (0 or 1)
            result.push_back((sum % 2) + '0');

            // Update the carry for the next position
            carry = sum / 2;
        }

        // The result is built backwards, so we must reverse it
        std::reverse(result.begin(), result.end());
        return result;
    }
};
