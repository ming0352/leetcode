/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) { // 背包
            for (int j = 0; j <= i; j++) {    // 物品
                string tmp = s.substr(j, i - j);
                if (dp[j] && dict.find(tmp) != dict.end())
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
