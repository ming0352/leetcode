/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) {
            int zero = 0;
            int one = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '1')
                    one++;
                else
                    zero++;
            }
            for (int o = m; o >= zero; o--) {
                for (int g = n; g >= one; g--)
                    dp[o][g] = max(dp[o][g], dp[o - zero][g - one] + 1);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
