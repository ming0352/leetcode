/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        if (s.length() == 1)
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (st.empty() ||
                     (st.top() != '(' && s[i] == ')') ||
                     (st.top() != '[' && s[i] == ']') ||
                     (st.top() != '{' && s[i] == '}'))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end
