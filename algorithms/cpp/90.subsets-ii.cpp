/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int idx, vector<bool> &used) {
        if (idx > nums.size())
            return;
        result.push_back(path);
        for (int i = idx; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<bool> used = {0};
        used.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};
// @lc code=end
