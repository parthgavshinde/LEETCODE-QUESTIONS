class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* head = root; // The left-most node of the current level
        
        while (head != nullptr) {
            Node* dummy = new Node(0);
            Node* temp = dummy;
            
            // Traverse the current level using the 'next' pointers
            for (Node* curr = head; curr != nullptr; curr = curr->next) {
                if (curr->left != nullptr) {
                    temp->next = curr->left;
                    temp = temp->next;
                }
                if (curr->right != nullptr) {
                    temp->next = curr->right;
                    temp = temp->next;
                }
            }
            
            // Move to the next level
            head = dummy->next;
            delete dummy; // Clean up dummy node
        }
        
        return root;
    }
};
