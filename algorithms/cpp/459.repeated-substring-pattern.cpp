/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
  public:
    int *next = new int[10000];
    void build_next(string s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {

        build_next(s);
        int len = s.size();
        if (next[len - 1] != 0 && (len % (len - next[len - 1])) == 0)
            return true;

        return false;
    }
};

// method 2
/*
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s + s;
        tmp.erase(tmp.begin());
        tmp.erase(tmp.end() - 1);
        if (tmp.find(s) != string::npos)
            return true;
        else
            return false;
    }
};
*/
// @lc code=end
