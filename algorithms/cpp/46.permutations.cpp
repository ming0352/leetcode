/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> result;
    vector<int> path;
    int used[7] = {0};
    void backtracking(vector<int> &nums) {
        if (nums.size() == path.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {

            if (used[i] == 1)
                continue;
            path.push_back(nums[i]);
            used[i] = 1;
            backtracking(nums);
            used[i] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {

        backtracking(nums);
        return result;
    }
};
// @lc code=end
