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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if no reversal is needed or list is empty
        if (!head || left == right) {
            return head;
        }
        
        // Dummy node helps handle the case where left = 1 seamlessly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 1. Reach the node just before the 'left' position
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // 2. Initialize pointers for the sublist reversal
        ListNode* curr = prev->next; // The first node to be reversed
        ListNode* nextNode = nullptr; // Temporary pointer to store the next node
        
        // 3. Reverse the sublist by shifting nodes iteratively
        for (int i = 0; i < right - left; ++i) {
            nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        
        // Clean up memory and return the actual head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};