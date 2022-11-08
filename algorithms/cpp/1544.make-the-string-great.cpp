/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
 public:
  string makeGood(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
      ans.push_back(s[i]);
      while (ans.size() && ((ans.back() - 32 == s[i + 1] - 0) ||
                            (ans.back() + 32 == s[i + 1] - 0))) {
        ans.pop_back();
        i++;
      }
    }
    return ans;
  }
};
