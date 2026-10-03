#include <stack>

class MyQueue {
public:
    std::stack<int> input;
    std::stack<int> output;

    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int val = peek();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
