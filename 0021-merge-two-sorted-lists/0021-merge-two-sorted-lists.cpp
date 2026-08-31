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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting anchor
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Loop until one of the lists becomes empty
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;   // Link the smaller node
                list1 = list1->next;  // Move to the next node in list1
            } else {
                tail->next = list2;   // Link the smaller node
                list2 = list2->next;  // Move to the next node in list2
            }
            tail = tail->next;        // Move the tail pointer forward
        }
        
        // Attach the remaining non-empty list segment
        tail->next = (list1 != nullptr) ? list1 : list2;
        
        // The merged list begins right after the dummy node
        return dummy.next;
    }
};