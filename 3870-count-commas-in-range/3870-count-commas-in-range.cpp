class Solution {
public:
    long long countCommas(long long n) {
        long long length = 1;
        long long p10 = 1;
        long long res = 0;
        
        while (p10 * 10 - 1 < n) {
            res += (length - 1) / 3 * p10 * 9;
            p10 *= 10;
            length++;
        }
        res += (length - 1) / 3 * (n - p10 + 1);
        return res;
    }
};