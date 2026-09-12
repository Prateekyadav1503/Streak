#include <vector>
#include <algorithm>
#include <tuple>

class Solution {
public:
    struct Result {
        long long weight;
        std::vector<int> selected;

        bool operator>(const Result& other) const {
            if (weight != other.weight) return weight > other.weight;
            return selected < other.selected;
        }
    };

    std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        std::vector<std::tuple<int, int, int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        std::sort(arr.begin(), arr.end());

        // Memoization table: memo[i][quota]
        std::vector<std::vector<Result>> memo(n + 1, std::vector<Result>(5, {-1, {}}));

        auto solve = [&](auto& self, int i, int quota) -> Result {
            if (i == n || quota == 0) return {0, {}};
            if (memo[i][quota].weight != -1) return memo[i][quota];

            // Option 1: Skip current interval
            Result skip = self(self, i + 1, quota);

            // Option 2: Pick current interval
            auto [l, r, weight, orig_idx] = arr[i];
            
            // Find next non-overlapping interval using binary search
            int j = n;
            int low = i + 1, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (std::get<0>(arr[mid]) > r) {
                    j = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            Result next_res = self(self, j, quota - 1);
            std::vector<int> cur_selected = {orig_idx};
            cur_selected.insert(cur_selected.end(), next_res.selected.begin(), next_res.selected.end());
            std::sort(cur_selected.begin(), cur_selected.end());

            Result pick = {weight + next_res.weight, cur_selected};

            if (pick > skip) {
                return memo[i][quota] = pick;
            }
            return memo[i][quota] = skip;
        };

        return solve(solve, 0, 4).selected;
    }
};
