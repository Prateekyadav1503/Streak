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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nxt = curr->next; // 1. Save the next node
            curr->next = prev;          // 2. Reverse the link
            prev = curr;                // 3. Move prev one step forward
            curr = nxt;                 // 4. Move curr one step forward
        }
        
        return prev; // prev will
    }
};