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
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = head;
        ListNode* second = nullptr;
        ListNode* third = nullptr;
        ListNode* prev_second = nullptr;
        ListNode* new_head = (head == nullptr or head->next == nullptr) ? head : head->next;
        
        while (first != nullptr) {
            ListNode* second = first->next;
            ListNode* third = second == nullptr ? nullptr : second->next;
            if (second == nullptr) {
                if (prev_second != nullptr) {
                    prev_second->next = first;
                }
            } else {
                second->next = first;
                first->next = nullptr;
                if (prev_second != nullptr) {
                    prev_second->next = second;
                }
            }

            prev_second = first;
            first = third;
            
        }
        return new_head;
    }
};
