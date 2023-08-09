/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
// class Solution {
//   public:
//     vector<vector<int>> result;
//     vector<int> path;
//     void backtracking(vector<int> &nums, int idx, vector<bool> &used) {
//         if (path.size() >= 2) {
//             result.push_back(path);
//         }
//         for (int i = idx; i < nums.size(); i++) {
//             if(i>0 &&nums[i] < nums[i - 1]) continue;
//             if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
//                 continue;
//             }
            
//             path.push_back(nums[i]);
//             used[i] = true;
//             backtracking(nums, i + 1, used);
//             path.pop_back();
//             used[i] = false;
//         }
//     }
//     vector<vector<int>> findSubsequences(vector<int> &nums) {
//         vector<bool> used = {false};
//         used.resize(nums.size());
//         backtracking(nums, 0, used);
//         return result;
//     }
// };
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        unordered_set<int> uset; 
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                    || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
            uset.insert(nums[i]); 
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
