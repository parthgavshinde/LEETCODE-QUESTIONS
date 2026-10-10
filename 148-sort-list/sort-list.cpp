class Solution {
public:
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        while (head != nullptr) {
            pq.push(head);
            head = head->next;
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (!pq.empty()) {
            current->next = pq.top();
            pq.pop();
            current = current->next;
        }
        
        // CRUCIAL FIX: Terminate the list to prevent cycles
        current->next = nullptr; 
        
        return dummy->next;
    }
};
