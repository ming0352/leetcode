/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
 public:
  void reverse(string& s, int i, int j) {
    for (; i < j;) {
      swap(s[i++], s[j--]);
    }
  }
  string reverseWords(string s) {
    int i = 0, j = 0;
    int slow = 0, fast = 0;
    //去除前面空格
    while (s[fast] == ' ') fast++;
    //去除中間空格
    for (; fast < s.size(); fast++) {
      if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
        continue;
      else {
        s[slow++] = s[fast];
      }
    }
    //去除最後的空格
    if (s[slow - 1] == ' ') {
      s.resize(slow - 1);
    } else {
      s.resize(slow);
    }
    reverse(s, 0, s.size() - 1);
    while (i < s.size()) {
        //先找到第一個word
      while (s[j] != ' ' && j < s.size()) j++;
      //將第一個word reverse
      reverse(s, i, j - 1);
      i = ++j; //重設i為下一個字的開頭
    }
    return s;
  }
};

// @lc code=end
