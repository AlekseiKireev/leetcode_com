#include <stack>

class MyQueue {
private:
    std::stack<int> s1;
    std::stack<int> s2;
    int front;

public:
    MyQueue() {
    }

    // Push element x to the back of queue.
    void push(int x) {
        if (s1.empty()) {
            front = x;
        }
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }

    // Get the front element.
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        return front;
    }

    // Return whether the queue is empty.
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

