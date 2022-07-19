/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> hash;
    int ans = 0;
    while (1) {
        //count sum
      while (n > 0) { 
        int q = n % 10;
        ans += q * q;
        n /= 10;
      }
      //check 是否重複
      if (hash.find(ans) != hash.end()) {
        return false;
      } else {
        if (ans == 1) return true;
        hash.insert(ans);
        n = ans;
        ans = 0;
      }
    }

    return false;
  }
};
// @lc code=end
