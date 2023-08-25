/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        int hash[27];
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int right = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (right == i) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
// @lc code=end
