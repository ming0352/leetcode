/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
  public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}
    void push(int x) { st1.push(x); }
    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int value = st2.top();
        st2.pop();
        return value;
    }
    int peek() {
        int x;
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        x = st2.top();
        return x;
    }
    bool empty() { return st1.empty() && st2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
