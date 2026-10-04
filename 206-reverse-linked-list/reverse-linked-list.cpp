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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head ;
        ListNode* temp = head ; 
        ListNode* prev = nullptr ;

        ListNode* temp2 = head->next;

        while(temp2 !=nullptr)
        {
           temp->next = prev ; 
            prev = temp ; 
            temp = temp2 ;
            temp2 = temp2->next ;
        }
         temp->next = prev ; 
            prev = temp ; 
            
        return temp;
    }
};