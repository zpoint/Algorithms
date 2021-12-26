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
        ListNode* node1 = list1, *node2 = list2;
        ListNode* head = nullptr, *tail = nullptr;
        while (node1 != nullptr or node2 != nullptr) {
            if (node1 == nullptr or (node2 != nullptr and (node1->val > node2->val))) {
                if (head == nullptr) {
                    head = tail = node2;
                } else {
                    tail->next = node2;
                    tail = node2;
                }
                node2 = node2->next;

            } else {
                if (head == nullptr) {
                    head = tail = node1;
                } else {
                    tail->next = node1;
                    tail = node1;
                }
                node1 = node1->next;
            }
        }
        return head;
    }
};
