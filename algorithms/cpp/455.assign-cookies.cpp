/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int max_count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                max_count++;
                index--;
            }
        }
        return max_count;
    }
};
// @lc code=end
