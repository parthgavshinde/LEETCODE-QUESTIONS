class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        
        // Traverse down the tree level by level
        while (curr != nullptr) {
            Node dummy(0);      // Acts as the head before the next level
            Node* tail = &dummy; // Used to build the next level's linked list
            
            // Traverse across the current level
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }
            
            // Move to the first node of the next level
            curr = dummy.next;
        }
        
        return root;
    }
};
