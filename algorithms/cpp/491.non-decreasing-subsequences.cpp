/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

@lc code = start class Solution {
  public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int idx) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        unordered_set<int> uset;
        for (int i = idx; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) ||
                (uset.find(nums[i]) != uset.end())) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
