/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
//Ｏ(nlogn)
// class Solution {
//  public:
//   vector<int> searchRange(vector<int>& nums, int target) {
//     int mid, n = nums.size();
//     int low = 0, high = nums.size() - 1;
//     int left, right;
//     if (n == 0)
//       return vector<int>({-1, -1});
//     else if (n == 1) {
//       if (nums[0] == target) return vector<int>({0, 0});
//     }
//     while (low <= high) {
//       mid = (low + high) / 2;
//       if (target > nums[mid]) {
//         low = mid + 1;
//         left = low;
//       } else if (target < nums[mid]) {
//         high = mid - 1;
//         right = high;
//       } else {
//         left = mid;
//         right = mid;
//         while (left > 0 && nums[left - 1] == nums[mid]) {
//           if (left > 0) left--;
//         }
//         while (right < nums.size() - 1 && nums[right + 1] == nums[mid]) {
//           if (right < nums.size() - 1) right++;
//         }
//         return vector<int>({left, right});
//       }
//     }
//     return vector<int>({-1, -1});
//   }
// };

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int mid, n = nums.size();
    vector<int> ans(2, -1);
    int low = 0, high = nums.size() - 1;
    int left, right;
    int tmid, tleft, tright;
    if (n == 0)
      return vector<int>({-1, -1});
    else if (n == 1) {
      if (nums[0] == target) return vector<int>({0, 0});
    }

    //尋找右邊界
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (target > nums[mid]) {
        low = mid + 1;
      } else if (target < nums[mid]) {
        high = mid - 1;
      } else {
        if (mid == nums.size() - 1 || nums[mid + 1] != nums[mid]) {
          ans[1] = mid;
          break;
        } else {
          low = mid + 1;
          ans[1] = low;
        }
      }
    }
    //尋找左邊界
    low = 0;
    high = nums.size() - 1;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (target > nums[mid]) {
        low = mid + 1;

      } else if (target < nums[mid]) {
        high = mid - 1;

      } else {
        if (mid == 0 || nums[mid - 1] != nums[mid]) {
          ans[0] = mid;
          break;
        } else {
          high = mid - 1;
          ans[0] = high;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
