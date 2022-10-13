/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<long long> st;
        long long a, b;
        long long ans = 0;
        for (int i = 0; i < tokens.size();) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                switch (tokens[i++][0]) {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(a - b);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push((a - (a % b)) / b);
                    break;
                }
            } else {
                st.push(stol(tokens[i++]));
            }
        }
        ans = st.top();
        return ans;
    }
};
// @lc code=end
