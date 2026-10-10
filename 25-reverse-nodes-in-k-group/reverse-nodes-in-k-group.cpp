class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;

        while (true) {
            // Find the k-th node from prevGroupTail
            ListNode* kth = prevGroupTail;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            
            // If less than k nodes remain, leave them as is
            if (!kth) break;

            ListNode* nextGroupHead = kth->next;
            
            // Reverse the k nodes
            ListNode* prev = nextGroupHead; 
            ListNode* curr = prevGroupTail->next;
            for (int i = 0; i < k; ++i) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            // Reconnect the newly reversed group
            ListNode* tail = prevGroupTail->next; 
            prevGroupTail->next = kth;            
            prevGroupTail = tail;                 
        }

        return dummy.next;
    }
};
