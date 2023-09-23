/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
// class Solution {
//   public:
//     int maxProfit(vector<int> &prices) {
//         int result = 0;
//         for (int i = 1; i < prices.size(); i++) {
//             int diff = prices[i] - prices[i - 1];
//             if (diff > 0) {
//                 result += diff;
//             }
//         }
//         return result;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[len - 1][1];
    }
};
// @lc code=end
