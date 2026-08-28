class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            // Update the minimum price encountered so far
            minPrice = min(minPrice, price);
            
            // Calculate potential profit and update max profit
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};