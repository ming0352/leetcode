/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
  public:
    int divide(int dividend, int divisor) {
        int max = pow(2, 31) - 1;
        int min = -pow(2, 31);
        if (dividend == min && divisor == -1)
            return max;
        int ans = (dividend - dividend % divisor) / divisor;
        if (ans > max)
            return max;
        else if (ans < min)
            return min;
        return ans;
    }
};
// @lc code=end
