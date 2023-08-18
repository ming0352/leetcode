/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int cursum = 0;
        int total_sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            cursum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (cursum < 0) {
                cursum = 0;
                start=i+1;
            }
        }
        if (total_sum < 0)
            return -1;
        return start;
    }
};
// @lc code=end
