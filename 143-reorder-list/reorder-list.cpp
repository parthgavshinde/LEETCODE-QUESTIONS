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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==nullptr) return  ;
        ListNode* fast = head ;
        ListNode* slow = head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        
        ListNode* curr = slow->next ;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(curr!=nullptr)
        {
            ListNode* nextnode = curr->next ;
            curr->next = prev ;
            prev = curr;
            curr = nextnode;
        }

        ListNode* left = head ; 
        ListNode* right = prev;

        while(right!=nullptr)
        {
            ListNode* lnext = left->next ;
            ListNode* rnext = right->next;
            left->next =right;
            right->next = lnext;
            
            left = lnext;
            right =rnext;
        }




    }
};