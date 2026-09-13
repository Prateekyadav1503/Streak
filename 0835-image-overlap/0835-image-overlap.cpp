class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> p1, p2;

        // Collect coordinates of all 1s in both images
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) p1.push_back({r, c});
                if (img2[r][c] == 1) p2.push_back({r, c});
            }
        }

        // Count frequencies of each shift vector (r2 - r1, c2 - c1)
        std::unordered_map<int, int> shift_count;
        int max_overlaps = 0;

        for (auto& a : p1) {
            for (auto& b : p2) {
                int r_shift = b.first - a.first;
                int c_shift = b.second - a.second;
                // Encode the pair (r_shift, c_shift) into a single integer key
                int key = r_shift * 100 + c_shift;
                shift_count[key]++;
                max_overlaps = std::max(max_overlaps, shift_count[key]);
            }
        }

        return max_overlaps;
    }
};