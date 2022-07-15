/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    // multimap<char, int> mmap_s;
    // multimap<char, int> mmap_t;
    // if (s.size() != t.size()) return false;
    // for (int i = 0; i < s.size(); i++) {
    //   mmap_s.insert(make_pair(s[i], 0));
    // }
    // for (int i = 0; i < t.size(); i++) {
    //   mmap_t.insert(make_pair(t[i], 0));
    // }
    // for (int i = 0; i < s.size(); i++) {
    //   if (mmap_t.erase(s[i]) != mmap_s.erase(s[i])) {
    //     return false;
    //   }
    // }
    // return true;
    int arr[26] = {0};
    if (s.size() != t.size()) return false;
    for (int i = 0; i < s.size(); i++) {
      arr[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
      arr[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (arr[i] != 0) return false;
    }
    return true;
  }
};
// @lc code=end
