/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
 public:
  void swap(char& a, char& b) {
    char t = a;
    a = b;
    b = t;
  }
  void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;
    for (; i < j;) {
      swap(s[i++], s[j++]);
    }
  }
};
// @lc code=end
