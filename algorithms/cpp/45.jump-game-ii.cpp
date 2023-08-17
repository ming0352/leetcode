/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
  public:
    int jump(vector<int> &nums) {
        int c = 0;
        if (nums.size() == 1)
            return 0;
        int next = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            next = max(next, nums[i] + i);
            if (i == cur) {
                if (cur != nums.size() - 1) {
                    c++;
                    cur = next;
                    if (cur >= nums.size() - 1)
                        break;
                }
            }
        }
        return c;
    }
};
// @lc code=end
