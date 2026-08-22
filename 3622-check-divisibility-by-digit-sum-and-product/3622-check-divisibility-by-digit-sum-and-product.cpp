class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int temp = n;
        
        // Extract digits one by one
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
            temp /= 10;
        }
        
        // Check if n is divisible by the sum of digitSum and digitProduct
        return (n % (digitSum + digitProduct) == 0);
    }
};