/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // We need at least 3 nodes to have a critical point
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCP = -1; // Index of the very first critical point found
        int prevCP = -1;  // Index of the most recent critical point found
        int minDistance = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currentIndex = 1; // 0-indexed position tracker

        while (curr->next != nullptr) {
            ListNode* nxt = curr->next;

            // Check if curr is a local maxima or local minima
            bool isMaxima = (curr->val > prev->val && curr->val > nxt->val);
            bool isMinima = (curr->val < prev->val && curr->val < nxt->val);

            if (isMaxima || isMinima) {
                if (firstCP == -1) {
                    firstCP = currentIndex; // Record the first ever critical point
                } else {
                    // Update the minimum distance between adjacent critical points
                    minDistance = min(minDistance, currentIndex - prevCP);
                }
                prevCP = currentIndex; // Update the last seen critical point
            }

            // Move pointers forward
            prev = curr;
            curr = nxt;
            currentIndex++;
        }

        // If fewer than two critical points were found, return {-1, -1}
        if (firstCP == prevCP) {
            return {-1, -1};
        }

        // Maximum distance is always between the very first and very last critical point
        int maxDistance = prevCP - firstCP;

        return {minDistance, maxDistance};
    }
};