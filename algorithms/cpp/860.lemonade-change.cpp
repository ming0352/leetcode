/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
  public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int i = 0; i < bills.size(); i++) {
            switch (bills[i]) {
            case 5:
                five++;
                break;
            case 10:
                if (five < 1)
                    return false;
                ten++;
                five--;
                break;
            case 20:
                if (five > 0 && ten > 0) {
                    ten--;
                    five--;
                    twenty++;
                } else if (five >= 3) {
                    five -= 3;
                    twenty++;
                } else
                    return false;
                break;
            }
        }
        return true;
    }
};
// @lc code=end
