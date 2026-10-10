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
    // Custom comparator to make the priority queue a min-heap
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val; 
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Initialize min-heap with the custom comparator
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // Push the head of each non-empty list into the priority queue
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }
        
        // Dummy node to easily build the result list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Extract the minimum node and push its next node back into the queue
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }
        
        return dummy.next; // Corrected line
    }
}; // Added missing semicolon
