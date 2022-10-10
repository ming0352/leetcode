/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
  public:
    queue<int> q1;
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop() {
        int n = q1.size();
        n--;
        while (n--) {
            q1.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() { return q1.back(); }

    bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
