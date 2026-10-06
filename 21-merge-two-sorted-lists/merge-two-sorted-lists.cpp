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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1; 

        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* headp ;
        if(left->val <= right->val) headp = left;
        else headp = right;
       
       ListNode* dummy = new ListNode(0);

        while(left!=nullptr && right!=nullptr)
        {

             if(left->val <= right->val)
            {
                dummy->next = left ;
                dummy = dummy->next;
                left = left->next;
            }
            else if(left->val > right->val)
            {
                dummy->next = right ;
                dummy = dummy->next;
                right = right->next;
            }
        }
        while(left!=nullptr)
        {
            dummy->next = left ;
            left = left->next;
            dummy=dummy->next;
        }
        while(right!=nullptr)
        {
            dummy->next = right ;
            right = right->next;
            dummy=dummy->next;
        }
        return headp;
    }
};