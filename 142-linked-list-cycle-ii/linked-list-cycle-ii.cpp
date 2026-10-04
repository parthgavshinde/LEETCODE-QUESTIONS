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
    ListNode *detectCycle(ListNode *head) {

        ListNode* fast = head ;
        ListNode* slow = head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next ;
            if(slow==fast) 
            {
                ListNode* temp = head ; 
                while(temp!=fast)
                {

                    fast = fast->next;
                    temp = temp->next;
                }
                return temp;
            }
            
        } 
        

        return nullptr;
    }
};