/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN, c = 0;
        for (int i = 0; i < nums.size(); i++) {
            c += nums[i];
            result = c > result ? c : result;
            if (c < 0) {
                c = 0;
            }
        }
        return result;
    }
};
// @lc code=end
