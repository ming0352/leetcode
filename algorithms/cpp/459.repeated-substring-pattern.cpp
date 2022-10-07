/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s + s;
        tmp.erase(tmp.begin());
        tmp.erase(tmp.end() - 1);
        if (tmp.find(s) != string::npos)
            return true;
        else
            return false;
    }
};
// @lc code=end
