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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==nullptr) return true ;
        ListNode* fast = head ;
        
        ListNode* slow = head;



        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next ;
            slow = slow->next ; 
        }
         ListNode* temp = slow;
         ListNode* prev = nullptr;

         while(temp!=nullptr)
         {ListNode* nextnode = temp->next ;
            temp->next = prev;
            prev = temp ;
            temp = nextnode ; 
         }

         ListNode* left = head ;
         ListNode* right = prev ; 

         while(right!=nullptr)
         {
            if(left->val != right->val ) return false;
            left = left->next;
            right = right->next;
         }

         return true; 

    }
};