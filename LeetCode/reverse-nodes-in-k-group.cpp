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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {return head;}
        
        std::vector<ListNode*> arr;
        arr.reserve(k);
        for (auto i = 0; i < k; ++i) {arr[i] = nullptr; }
        
        ListNode* curr_ptr = head;
        ListNode* prev_tail = nullptr;
        int i = 0;
        while (curr_ptr != nullptr) {
            arr[i++] = curr_ptr;
            curr_ptr = curr_ptr->next;
            if (i >= k) {
                for (int j = k-1; j > 0; --j) {
                    arr[j]->next = arr[j-1];
                }
                if (prev_tail != nullptr) {
                    prev_tail->next = arr[k-1];
                } else {
                    head = arr[k-1];
                }
                prev_tail = arr[0];
                i = 0;
            }
        }
        if (i > 0) {
            prev_tail->next = arr[0];
        } else {
            prev_tail->next = nullptr;
        }

        return head;
    }
};
