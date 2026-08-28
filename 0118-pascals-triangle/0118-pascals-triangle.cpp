class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < numRows; ++i) {
            // Create a row initialized with 1s. The i-th row has (i + 1) elements.
            vector<int> row(i + 1, 1);
            
            // Fill in the internal elements using the previous row
            for (int j = 1; j < i; ++j) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};