/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> result;
    vector<int> path;
    // bool sum_vector(vector<int> p, int n) {
    //     int s = 0;
    //     for (int i = 0; i < p.size(); i++) {
    //         s += p[i];
    //     }
    //     return s == n;
    // }
    void backtracking(int k, int n, int start, int sum) {
        if (path.size() > k || sum > n) {
            return;
        }
        if (sum == n && path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < 10; i++) {
            path.push_back(i);
            sum += i;
            backtracking(k, n, i + 1, sum);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return result;
    }
};
// @lc code=end
