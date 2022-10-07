/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution {
  public:
    bool find132pattern(vector<int> &nums) {
        int min = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < min) {
                return true;
            } else {
                while (!st.empty() && nums[i] > st.top()) {
                    min = st.top();
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end
