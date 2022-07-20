/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    // unordered_map<int, int> nmap;
    // for (char i : magazine) {
    //   nmap[i]++;
    // }
    // for (char k : ransomNote) {
    //   if (nmap.find(k) != nmap.end() && nmap[k] != 0) {
    //     nmap[k]--;
    //   } else if (nmap.find(k) == nmap.end() || nmap[k] == 0)
    //     return false;
    // }
    // return true;

    //使用int array來當成hash table
    int a[26] = {0};
    for (char i : magazine) {
      a[i - 'a']++;
    }
    for (char i : ransomNote) {
      if (a[i - 'a'] == 0) {
        return false;
      }
      a[i - 'a']--;
    }
    return true;
  }
};
// @lc code=end
