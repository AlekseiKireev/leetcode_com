#include <stack>

class MyQueue {
private:
    std::stack<int> s1;
    std::stack<int> s2; // upd in int pop()
    int front;

public:
    MyQueue() {
    }

    // Push element x to the back of queue.
    void push(int x) { // == deque::push_back
        if (s1.empty()) {
            front = x;
        }
        s1.push(x);
    }

    int pop() { // == deque::pop_front
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
    int peek() { // == deque::front
        if (!s2.empty()) {
            return s2.top();
        }
        return front;
    }

    // Return whether the queue is empty.
    bool empty() { // == deque::empty
        return s1.empty() && s2.empty();
    }
};
/*
#include <stack>

class MyQueue {
private:
    std::stack<int> BackQueue;
    std::stack<int> FrontReverseQueue;
    int front;

public:
    MyQueue() {
    }

    // Push element x to the back of queue.
    void push(int x) {
        if (BackQueue.empty()) {
            front = x;
        }
        BackQueue.push(x);
    }

    int pop() {
        if (FrontReverseQueue.empty()) {
            while (!BackQueue.empty()) {
                FrontReverseQueue.push(BackQueue.top());
                BackQueue.pop();
            }
        }
        int result = FrontReverseQueue.top();
        FrontReverseQueue.pop();
        return result;
    }

    // Get the front element.
    int peek() {
        if (!FrontReverseQueue.empty()) {
            return FrontReverseQueue.top();
        }
        return front;
    }

    // Return whether the queue is empty.
    bool empty() {
        return BackQueue.empty() && FrontReverseQueue.empty();
    }
};

*/
