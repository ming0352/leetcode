/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int idx) {
        if (idx > nums.size())
            return;
        result.push_back(path);
        for (int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
