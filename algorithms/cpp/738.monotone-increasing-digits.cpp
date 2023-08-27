/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
class Solution {
  public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int flag = s.size();
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};
// @lc code=end
