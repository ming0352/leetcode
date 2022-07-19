/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> u1;
    // add nums1 and nums2
    for (int j : nums1) {
      for (int k : nums2) {
        u1[j + k]++;
      }
    }
    int count = 0;
    for (int j : nums3) {
      for (int k : nums4) {
        if (u1.find(0 - (j + k)) != u1.end()) {
          count += u1[0 - (j + k)];
        }
      }
    }

    return count;
  }
};
// @lc code=end
