class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1; 

        // Ek dummy node banayein jo merged list ke starting se pehle rahega
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy; // Isko use karke hum list aage badhayenge

        ListNode* left = list1;
        ListNode* right = list2;

        // Jab tak dono list mein elements hain
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        // Jo list bach gayi hai (left ya right), usko seedha attach kar dein
        if (left != nullptr) {
            current->next = left;
        } 
        if (right != nullptr) {
            current->next = right;
        }

        // Asli head dummy->next par hai
        ListNode* result = dummy->next;
        delete dummy; // C++ mein memory leak bachane ke liye (optional in LeetCode but good practice)
        
        return result;
    }
};
