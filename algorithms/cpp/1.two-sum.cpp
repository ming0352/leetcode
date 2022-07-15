/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
//  O(n^2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> answer;
//         for(int i=0 ; i<nums.size() ;i++)
//         {
//             for(int j=i+1;j<nums.size();j++){
//                if(nums[i]+nums[j] == target)
//                {
//                    answer.push_back(i);
//                    answer.push_back(j);
//                }
//             }
//         }
//         return answer;
//     }

// };
//O(N)
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      if (hash.find(target - nums[i]) != hash.end() &&
          i != hash[target - nums[i]]) {
        answer.emplace_back(i);
        answer.emplace_back(hash[target - nums[i]]);
        break;
      }
      hash.insert(make_pair(nums[i], i));
    }
    return answer;
  }
};
// @lc code=end
