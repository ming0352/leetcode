/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
//解題思路
// 1.使用Disflag=0 1 2 3  分別代表右下左上四個方向
// 2.當走完一個方向時，將已走完的邊界＋＋或--，並將dirflag+1 %4
// 3.持續改變方向直到top!=down &&left!=right
// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int row = matrix.size();
    int column = matrix[0].size();
    int dirflag = 0, top = 0, down = row - 1, left = 0, right = column - 1;
    int i = top, j = left;

    while (top <= down && left <= right) {
      if (dirflag == 0) {
        for (j = left; j <= right; j++) {
          ans.emplace_back(matrix[top][j]);
        }
        top++;
      } else if (dirflag == 1) {
        for (i = top; i <= down; i++) {
          ans.emplace_back(matrix[i][right]);
        }
        right--;
      } else if (dirflag == 2) {
        for (j = right; j >= left; j--) {
          ans.emplace_back(matrix[down][j]);
        }
        down--;
      } else if (dirflag == 3) {
        for (i = down; i >= top; i--) {
          ans.emplace_back(matrix[i][left]);
        }
        left++;
      }
      dirflag = (dirflag + 1) % 4;
    }

    return ans;
  }
};
// @lc code=end
