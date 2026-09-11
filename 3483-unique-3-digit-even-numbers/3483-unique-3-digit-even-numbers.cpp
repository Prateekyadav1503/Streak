#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) {
            count[d]++;
        }
        
        int validCount = 0;
        
        // Iterate through all 3-digit even numbers
        for (int num = 100; num <= 998; num += 2) {
            int h = num / 100;
            int t = (num / 10) % 10;
            int u = num % 10;
            
            int req[10] = {0};
            req[h]++;
            req[t]++;
            req[u]++;
            
            bool possible = true;
            for (int i = 0; i < 10; i++) {
                if (req[i] > count[i]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                validCount++;
            }
        }
        
        return validCount;
    }
};
