/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
  public:
    static bool cmp(vector<int> x, vector<int> y) {
        return x[0] < y[0];

        int findMinArrowShots(vector<vector<int>> & points) {
            sort(points.begin(), points.end(), cmp);
            int c = 1;
            for (int i = 1; i < points.size(); i++) {
                if (points[i][0] > points[i - 1][1]) {
                    c++;
                } else {
                    points[i][1] = min(points[i - 1][1], points[i][1]);
                }
            }
            return c;
        }
    };
    // @lc code=end
