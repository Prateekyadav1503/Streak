class Solution {
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // Union the allowed swap indices
        for (auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }
        
        // Map each component root to a frequency map of elements in source
        unordered_map<int, unordered_map<int, int>> componentMap;
        for (int i = 0; i < n; ++i) {
            componentMap[find(i)][source[i]]++;
        }
        
        int mismatchCount = 0;
        
        // Check target elements against available source elements in the same component
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            if (componentMap[root][target[i]] > 0) {
                componentMap[root][target[i]]--;
            } else {
                mismatchCount++;
            }
        }
        
        return mismatchCount;
    }
};
