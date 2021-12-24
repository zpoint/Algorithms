public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // may leak memory
        ListNode* prev = head;
        ListNode* next = head;
        
        if (head == nullptr or n < 1) {
            return head;
        }
        
        int i = 0;
        for (; i < n; ++i) {
            next = next->next;
            if (next == nullptr) {
                // remove head
                return head->next;
            }
        }

        while (next->next != nullptr) {
            next = next->next;
            prev = prev->next;
        }
        
        prev->next = prev->next->next;
        return head;
    }
};
