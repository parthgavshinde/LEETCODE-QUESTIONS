#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {}
    
    // Push element x onto stack. Time: O(n)
    void push(int x) {
        q.push(x);
        int sz = q.size();
        // Rotate the previous elements behind the newly added element
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack and returns it. Time: O(1)
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    // Get the top element. Time: O(1)
    int top() {
        return q.front();
    }
    
    // Returns whether the stack is empty. Time: O(1)
    bool empty() {
        return q.empty();
    }
};
