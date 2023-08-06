/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
  private:
    vector<vector<string>> result;
    vector<string> path;
    string tmp;
    bool check(const string& k,int i,int j){
        for(;i<j;i++,j--){
            if(k[i]!=k[j]) return false;
        }
        return true;
    }
    void backtracking(string s, int starts) {
        if (s.size() <= starts) {
            result.push_back(path);
            return;
        }
        for (int i = starts; i < s.size(); i++) {
            
            if(check(s,starts,i)){
                string tmp = s.substr(starts,i-starts+1);
                path.push_back(tmp);
            }else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
    }

  public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end
