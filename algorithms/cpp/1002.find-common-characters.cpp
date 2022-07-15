/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    int hash[26] = {0};
    int otherhash[26] = {0};
    vector<string> ans;
    for (int i = 0; i < words[0].size(); i++) {
      hash[words[0][i] - 'a']++;
    }
    for (int i = 1; i < words.size(); i++) {
      memset(otherhash, 0, 26 * sizeof(int));
      for (int j = 0; j < words[i].size(); j++) {
        otherhash[words[i][j] - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        hash[i] = min(hash[i], otherhash[i]);
      }
    }
    for (int i = 0; i < 26; i++) {
      while (hash[i] != 0) {
        string a(1, i + 'a');
        ans.push_back(a);
        hash[i]--;
      }
    }
    return ans;
  }
};
// @lc code=end
