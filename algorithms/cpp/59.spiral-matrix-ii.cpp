/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
//解題思路
// 1.先計算最外圍迴圈執行次數(n/2)
// 2.再來用四個for迴圈執行填滿最外圈的動作
// 3.當田滿一圈後，將start_x,start_y,offset加一，縮小填入範圍
// 4.最終判斷如果n是奇數，則將中間空格填滿
//
// @lc code=start
//方法一
// class Solution {
//  public:
//   vector<vector<int>> generateMatrix(int n) {
//     vector<vector<int>> ans(n, vector<int>(n, 0));
//     int start_x = 0, start_y = 0, count = 1;
//     int offset = 1,loop=n/2;
//     int i, j;
//     while (loop--) {
//       for (j = start_y; j < n - offset; j++) {
//         ans[start_x][j] = count++;
//       }
//       for (i = start_x; i < n - offset; i++) {
//         ans[i][j] = count++;
//       }
//       for (; j > start_y; j--) {
//         ans[i][j] = count++;
//       }
//       for (; i > start_x; i--) {
//         ans[i][j] = count++;
//       }
//       start_x++;
//       start_y++;
//       offset++;
//     }
//     if(n%2==1){
//         ans[n/2][n/2]=count;
//     }
//     return ans;
//   }
// };

//方法二
//1.使用dir控制方向，並逐漸縮小範圍
//2.此方法與方法一的區別在於較有彈性，適用於任何 m*n matrix
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));

    int row = n;
    int column = n;
    int dirflag = 0, top = 0, down = row - 1, left = 0, right = column - 1;
    int i = top, j = left, count = 1;

    while (top <= down && left <= right) {
      if (dirflag == 0) {
        for (j = left; j <= right; j++) {
          ans[top][j] = count++;
        }
        top++;
      } else if (dirflag == 1) {
        for (i = top; i <= down; i++) {
          ans[i][right] = count++;
        }
        right--;
      } else if (dirflag == 2) {
        for (j = right; j >= left; j--) {
          ans[down][j] = count++;
        }
        down--;
      } else if (dirflag == 3) {
        for (i = down; i >= top; i--) {
          ans[i][left] = count++;
        }
        left++;
      }
      dirflag = (dirflag + 1) % 4;
    }

    return ans;
  }
};
// @lc code=end
