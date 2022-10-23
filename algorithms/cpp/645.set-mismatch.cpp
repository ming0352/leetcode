/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */
//方法一
//@lc code=start
// class Solution {
//   public:
//     vector<int> findErrorNums(vector<int> &nums) {
//         vector<int> answer;
//         int k = 1;
//         sort(nums.begin(), nums.end(), less<int>());
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == k)
//                 k++;
//             if (i > 0 && nums[i - 1] == nums[i]) {
//                 answer.push_back(nums[i]);
//             }
//         }
//         answer.push_back(k);
//         return answer;
//     }
// };
//方法二
class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> answer;
        vector<int> arr(100000);
        int k = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k)
                k++;
            if (arr[nums[i]] == 1) {
                answer.emplace_back(nums[i]);
            } else {
                arr[nums[i]]++;
            }
        }
        for (int i = 1; i < 100000; i++) {
            if (arr[i] == 0) {
                answer.emplace_back(i);
                break;
            }
        }
        return answer;
    }
};

// @lc code=end
