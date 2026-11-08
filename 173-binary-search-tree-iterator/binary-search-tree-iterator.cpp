class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper to push all left children of a given node
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        
        // If the popped node has a right child, push its entire left spine
        if (topNode->right != nullptr) {
            pushAllLeft(topNode->right);
        }
        
        return topNode->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
