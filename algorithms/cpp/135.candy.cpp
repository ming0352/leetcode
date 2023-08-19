/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
  public:
    int candy(vector<int> &ratings) {
        int result = 0;
        vector<int> Candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                Candy[i] = Candy[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                Candy[i - 1] = max(Candy[i] + 1, Candy[i - 1]);
            }
        }
        for (int i = 0; i < Candy.size(); i++) {
            result += Candy[i];
        }
        return result;
    }
};
// @lc code=end
