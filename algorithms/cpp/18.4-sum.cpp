/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, long target) {
    int offset1 = 1, offset2 = 1;
    vector<vector<int>> ans = {};
    sort(nums.begin(), nums.end());
    if (nums.size() < 4) return ans;
    int n = nums.size();
    for (int i = 0; i < nums.size() - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      if (nums[i] + nums[i + 1] > target - nums[i + 2] - nums[i + 3]) break;
      if (nums[i] + nums[n - 3] < target - nums[n - 2] - nums[n - 1]) continue;
      for (int j = i + 1; j < nums.size() - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        if (nums[i] + nums[j] > target - nums[j + 1] - nums[j + 2]) break;
        if (nums[i] + nums[j] < target - nums[n - 2] - nums[n - 1]) continue;
        int left = j + 1, right = nums.size() - 1;
        while (left < right) {
          if (target - nums[left] - nums[right] > nums[i] + nums[j]) {
            left++;
          } else if (target - nums[left] - nums[right] < nums[i] + nums[j]) {
            right--;
          } else {
            ans.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
            do {
              left++;
            } while (left < right && nums[left] == nums[left - 1]);
            do {
              right--;
            } while (left < right && nums[right] == nums[right + 1]);
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end
