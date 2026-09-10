#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int matchingNodesCount = 0;
        calculateSubtreeDetails(root, matchingNodesCount);
        return matchingNodesCount;
    }

private:
    // Returns a pair: {total_sum_of_subtree, total_count_of_nodes_in_subtree}
    std::pair<int, int> calculateSubtreeDetails(TreeNode* node, int& matchingNodesCount) {
        // Base case: An empty node contributes 0 to the sum and 0 to the node count
        if (node == nullptr) {
            return {0, 0};
        }

        // Post-order traversal: Collect details from left and right subtrees first
        auto [leftSum, leftCount] = calculateSubtreeDetails(node->left, matchingNodesCount);
        auto [rightSum, rightCount] = calculateSubtreeDetails(node->right, matchingNodesCount);

        // Aggregate current node's subtree data
        int totalSum = leftSum + rightSum + node->val;
        int totalCount = leftCount + rightCount + 1;

        // Check if the current node's value equals the floor integer average of its subtree
        if (totalSum / totalCount == node->val) {
            matchingNodesCount++;
        }

        return {totalSum, totalCount};
    }
};
