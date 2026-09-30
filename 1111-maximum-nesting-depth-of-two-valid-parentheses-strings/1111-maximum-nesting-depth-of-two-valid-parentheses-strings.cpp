#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> answer(seq.size());
        int depth = 0;

        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                // Assign current depth's parity (0 or 1) to the opening bracket
                answer[i] = depth % 2;
                depth++;
            } else { // seq[i] == ')'
                depth--;
                // Assign new depth's parity (0 or 1) to the closing bracket
                answer[i] = depth % 2;
            }
        }

        return answer;
    }
};