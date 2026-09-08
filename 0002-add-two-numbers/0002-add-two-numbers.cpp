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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to easily build and return the head of the new list
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        
        // Loop runs as long as there are digits left in l1 OR l2, or a remaining carry
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            if (l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }
            
            // Create a new node with the current digit value (carry % 10)
            curr->next = new ListNode(carry % 10);
            
            // Update the carry for the next position
            carry /= 10;
            
            // Advance the tracking pointer
            curr = curr->next;
        }
        
        return dummy.next;
    }
};