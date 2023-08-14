/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
  public:
    int wiggleMaxLength(vector<int> &nums) {
        int result = 1;
        int prediff = 0, curdiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            curdiff = nums[i] - nums[i - 1];
            if ((prediff <= 0 && curdiff > 0) ||
                (prediff >= 0 && curdiff < 0)) {
                result++;
                prediff = curdiff;
            }
        }

        return result;
    }
};
// @lc code=end
