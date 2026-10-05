/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;

        while(a!=b)
        {

            a = a->next;
            b = b->next;
            if(a==b) return a ; 
            if(a==nullptr) a = headB ;
            if(b==nullptr) b = headA ; 
        }

        
        return a ; 
    }
};