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
    // 1. You must define the 'compare' struct for the priority queue
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val; 
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(ListNode* node : lists)
        {
            if(node != nullptr) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty())
        {
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if(smallest->next != nullptr)
            {
                pq.push(smallest->next);
            }
        }
        
        // 2. Change 'head->next' to 'dummy->next'
        return dummy->next; 
    }
};
