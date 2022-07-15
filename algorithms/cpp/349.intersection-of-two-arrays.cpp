/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> a(nums1.begin(),nums1.end());
    unordered_set<int> result;
    for (auto n:nums2) {
      if(a.find(n)!=a.end()){
        result.insert(n);
      }
    }
    
    return vector<int>(result.begin(),result.end());
  }
};
// @lc code=end
